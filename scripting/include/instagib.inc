#if defined _instagib_included
	#endinput
#endif
#define _instagib_included

#define ROUNDTYPE_TDM (1 << 0)
#define ROUNDTYPE_FFA (1 << 1)

enum struct InstagibRound
{
	char name[64];
	char desc[128];
	
	bool is_special;
	bool disable_achievements;
	
	int roundtype_flags;
	int round_time;
	int minscore;
	float maxscore_multi;
	int points_per_kill;
	bool announce_win;
	bool allow_latespawn;
	bool allow_killbind;
	bool end_at_time_end;			// Whether the round will be forcefully ended when the round time is over
	int min_players_tdm;
	int min_players_ffa;
	bool ig_map_only;				// Whether the round is meant to be played only on instagib maps
	
	float railjump_velXY_multi;
	float railjump_velZ_multi;
	
	float respawn_time;
	float spawnuber_duration;
	
	Handle main_weapon; 			// TF2Items weapon handle
	int main_wep_clip;
	bool infinite_ammo;
}

// -------------------------------------------------------------------
/**
 * Called whenever player railjumps.
 *
 * @param client		Client index.
 * @param velocity		Client's velocity.
 */
forward void IG_OnRailjump(int client, float velocity[3]);

// -------------------------------------------------------------------
/**
 * Forces a special round.
 *
 * @param name			Round's name.
 * @param notify		Whether all players should get a chat notification.
 * @param client		If defined, will show that this client has forced the round.
 */
native void IG_ForceSpecialRound(char[] name, bool notify = false, int client = 0);

native void IG_GetCurrentRound(InstagibRound buffer, int size = sizeof(InstagibRound));

native int IG_GetTeamScore(int team);
native void IG_SetTeamScore(int team, int value);
native void IG_AddToTeamScore(int team, int amount);

native int IG_GetMaxScore();
native void IG_SetMaxScore(int amount);

/**
 * Returns client's place on the FFA leaderboards.
 *
 * @param name			Client index.
 *
 * @return				Client's place if the current round type is FFA, -1 otherwise.
 */
native int IG_GetClientLeaderboardsPlace(int client);

/**
 * Returns which client is located on the FFA leaderboards' defined place.
 *
 * @param place			Place on the leaderboards.
 *
 * @return				Client if the current round type is FFA, -1 otherwise.
 */
native int IG_GetClientFromLeaderboardsPlace(int place);

native bool IG_IsFFA();