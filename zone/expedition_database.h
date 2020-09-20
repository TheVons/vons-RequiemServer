/**
 * EQEmulator: Everquest Server Emulator
 * Copyright (C) 2001-2020 EQEmulator Development Team (https://github.com/EQEmu/Server)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY except by those people which sell it, which
 * are required to give you total support for your newly bought product;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef EXPEDITION_DATABASE_H
#define EXPEDITION_DATABASE_H

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Expedition;
class ExpeditionLockoutTimer;
struct ExpeditionMember;
class MySQLRequestResult;

namespace ExpeditionDatabase
{
	uint32_t InsertExpedition(
		const std::string& uuid, uint32_t instance_id, const std::string& expedition_name,
		uint32_t leader_id, uint32_t min_players, uint32_t max_players);
	std::string LoadExpeditionsSelectQuery();
	MySQLRequestResult LoadExpedition(uint32_t expedition_id);
	MySQLRequestResult LoadAllExpeditions();
	MySQLRequestResult LoadMembersForCreateRequest(
		const std::vector<std::string>& character_names, const std::string& expedition_name);
	std::vector<ExpeditionLockoutTimer> LoadCharacterLockouts(uint32_t character_id);
	std::vector<ExpeditionLockoutTimer> LoadCharacterLockouts(uint32_t character_id,
		const std::string& expedition_name);
	std::unordered_map<uint32_t, std::unordered_map<std::string, ExpeditionLockoutTimer>>
		LoadMultipleExpeditionLockouts(const std::vector<uint32_t>& expedition_ids);
	void DeleteAllMembers(uint32_t expedition_id);
	void DeleteMember(uint32_t expedition_id, uint32_t character_id);
	void DeleteAllCharacterLockouts(uint32_t character_id);
	void DeleteAllCharacterLockouts(uint32_t character_id, const std::string& expedition_name);
	void DeleteCharacterLockout(uint32_t character_id, const std::string& expedition_name, const std::string& event_name);
	void DeleteLockout(uint32_t expedition_id, const std::string& event_name);
	void DeleteMembersLockout(
		const std::vector<ExpeditionMember>& members, const std::string& expedition_name, const std::string& event_name);
	void AssignPendingLockouts(uint32_t character_id, const std::string& expedition_name);
	void DeletePendingLockouts(uint32_t character_id);
	void DeleteAllMembersPendingLockouts(const std::vector<ExpeditionMember>& members);
	uint32_t GetExpeditionIDFromCharacterID(uint32_t character_id);
	ExpeditionMember GetExpeditionLeader(uint32_t expedition_id);
	std::pair<std::vector<ExpeditionLockoutTimer>, std::vector<uint32_t>> GetMembersLockout(
		const std::vector<ExpeditionMember>& members, const std::string& expedition_name,
		const std::string& event_name);
	void InsertCharacterLockouts(
		uint32_t character_id, const std::vector<ExpeditionLockoutTimer>& lockouts,
		bool replace_timer, bool is_pending = false);
	void InsertMembersLockout(const std::vector<ExpeditionMember>& members, const ExpeditionLockoutTimer& lockout);
	void InsertLockout(uint32_t expedition_id, const ExpeditionLockoutTimer& lockout);
	void InsertLockouts(uint32_t expedition_id, const std::unordered_map<std::string, ExpeditionLockoutTimer>& lockouts);
	void InsertMember(uint32_t expedition_id, uint32_t character_id);
	void InsertMembers(uint32_t expedition_id, const std::vector<ExpeditionMember>& members);
	void UpdateLeaderID(uint32_t expedition_id, uint32_t leader_id);
	void UpdateLockState(uint32_t expedition_id, bool is_locked);
	void UpdateReplayLockoutOnJoin(uint32_t expedition_id, bool add_on_join);
	void AddLockoutDuration(const std::vector<ExpeditionMember>& members,
		const ExpeditionLockoutTimer& lockout, int seconds);
};

namespace LoadExpeditionColumns
{
	enum eLoadExpeditionColumns
	{
		id = 0,
		uuid,
		instance_id,
		expedition_name,
		leader_id,
		min_players,
		max_players,
		add_replay_on_join,
		is_locked,
		leader_name,
		member_id,
		member_name
	};
};

#endif
