// -------------------------------------------------------------------
void Menu_Main(int client)
{
	Menu menu = new Menu(MenuMain_Handler);
	
	menu.SetTitle("TF2Instagib v%s", INSTAGIB_VERSION);
	
	menu.AddItem("settings", "Settings");
	
	if (CheckCommandAccess(client, "forceround", ADMFLAG_CHEATS)) {
		menu.AddItem("forceround", "Force Special Round");
	}
	
	menu.AddItem("credits", "Credits");
	menu.Display(client, 60);
}

void Credits(int client)
{
	Panel panel = new Panel();
	
	char igtext[128];
	FormatEx(igtext, sizeof(igtext), "TF2Instagib v%s", INSTAGIB_VERSION);
	panel.DrawText(igtext);
	panel.DrawText("Made by Haxton Sale (76561197999759379)");
	
	panel.DrawText(" ");
	
	panel.DrawText("Source code is available at");
	panel.DrawText("https://github.com/haxtonsale/TF2Instagib");
	
	panel.DrawItem("Back");
	
	panel.Send(client, Credits_Handler, 60);
}

// -------------------------------------------------------------------
public int MenuMain_Handler(Menu menu, MenuAction action, int param1, int param2)
{
	if (action == MenuAction_Select) {
		char info[32];
		menu.GetItem(param2, info, sizeof(info));
		
		if (StrEqual(info, "settings")) {
			Menu_Settings(param1);
		} else if (StrEqual(info, "forceround")) {
			ClientCommand(param1, "forceround");
		} else if (StrEqual(info, "credits")) {
			Credits(param1);
		}
	} else if (action == MenuAction_End) {
		delete menu;
	}
}

public int Credits_Handler(Menu menu, MenuAction action, int param1, int param2)
{
	if (action == MenuAction_Select) {
		Menu_Main(param1);
	}
}