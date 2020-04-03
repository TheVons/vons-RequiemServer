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

#ifndef EQEMU_GUILD_RANKS_REPOSITORY_H
#define EQEMU_GUILD_RANKS_REPOSITORY_H

#include "../database.h"
#include "../string_util.h"

class GuildRanksRepository {
public:
	struct GuildRanks {
		int         guild_id;
		int8        rank;
		std::string title;
		int8        can_hear;
		int8        can_speak;
		int8        can_invite;
		int8        can_remove;
		int8        can_promote;
		int8        can_demote;
		int8        can_motd;
		int8        can_warpeace;
	};

	static std::string PrimaryKey()
	{
		return std::string("rank");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"guild_id",
			"rank",
			"title",
			"can_hear",
			"can_speak",
			"can_invite",
			"can_remove",
			"can_promote",
			"can_demote",
			"can_motd",
			"can_warpeace",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(implode(", ", Columns()));
	}

	static std::string InsertColumnsRaw()
	{
		std::vector<std::string> insert_columns;

		for (auto &column : Columns()) {
			if (column == PrimaryKey()) {
				continue;
			}

			insert_columns.push_back(column);
		}

		return std::string(implode(", ", insert_columns));
	}

	static std::string TableName()
	{
		return std::string("guild_ranks");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			ColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			InsertColumnsRaw()
		);
	}

	static GuildRanks NewEntity()
	{
		GuildRanks entry{};

		entry.guild_id     = 0;
		entry.rank         = 0;
		entry.title        = "";
		entry.can_hear     = 0;
		entry.can_speak    = 0;
		entry.can_invite   = 0;
		entry.can_remove   = 0;
		entry.can_promote  = 0;
		entry.can_demote   = 0;
		entry.can_motd     = 0;
		entry.can_warpeace = 0;

		return entry;
	}

	static GuildRanks GetGuildRanksEntry(
		const std::vector<GuildRanks> &guild_rankss,
		int guild_ranks_id
	)
	{
		for (auto &guild_ranks : guild_rankss) {
			if (guild_ranks.rank == guild_ranks_id) {
				return guild_ranks;
			}
		}

		return NewEntity();
	}

	static GuildRanks FindOne(
		int guild_ranks_id
	)
	{
		auto results = database.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				guild_ranks_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			GuildRanks entry{};

			entry.guild_id     = atoi(row[0]);
			entry.rank         = atoi(row[1]);
			entry.title        = row[2];
			entry.can_hear     = atoi(row[3]);
			entry.can_speak    = atoi(row[4]);
			entry.can_invite   = atoi(row[5]);
			entry.can_remove   = atoi(row[6]);
			entry.can_promote  = atoi(row[7]);
			entry.can_demote   = atoi(row[8]);
			entry.can_motd     = atoi(row[9]);
			entry.can_warpeace = atoi(row[10]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		int guild_ranks_id
	)
	{
		auto results = database.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				guild_ranks_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		GuildRanks guild_ranks_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[2] + " = '" + EscapeString(guild_ranks_entry.title) + "'");
		update_values.push_back(columns[3] + " = " + std::to_string(guild_ranks_entry.can_hear));
		update_values.push_back(columns[4] + " = " + std::to_string(guild_ranks_entry.can_speak));
		update_values.push_back(columns[5] + " = " + std::to_string(guild_ranks_entry.can_invite));
		update_values.push_back(columns[6] + " = " + std::to_string(guild_ranks_entry.can_remove));
		update_values.push_back(columns[7] + " = " + std::to_string(guild_ranks_entry.can_promote));
		update_values.push_back(columns[8] + " = " + std::to_string(guild_ranks_entry.can_demote));
		update_values.push_back(columns[9] + " = " + std::to_string(guild_ranks_entry.can_motd));
		update_values.push_back(columns[10] + " = " + std::to_string(guild_ranks_entry.can_warpeace));

		auto results = database.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				implode(", ", update_values),
				PrimaryKey(),
				guild_ranks_entry.rank
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static GuildRanks InsertOne(
		GuildRanks guild_ranks_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back("'" + EscapeString(guild_ranks_entry.title) + "'");
		insert_values.push_back(std::to_string(guild_ranks_entry.can_hear));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_speak));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_invite));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_remove));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_promote));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_demote));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_motd));
		insert_values.push_back(std::to_string(guild_ranks_entry.can_warpeace));

		auto results = database.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				implode(",", insert_values)
			)
		);

		if (results.Success()) {
			guild_ranks_entry.id = results.LastInsertedID();
			return guild_ranks_entry;
		}

		guild_ranks_entry = InstanceListRepository::NewEntity();

		return guild_ranks_entry;
	}

	static int InsertMany(
		std::vector<GuildRanks> guild_ranks_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &guild_ranks_entry: guild_ranks_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back("'" + EscapeString(guild_ranks_entry.title) + "'");
			insert_values.push_back(std::to_string(guild_ranks_entry.can_hear));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_speak));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_invite));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_remove));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_promote));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_demote));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_motd));
			insert_values.push_back(std::to_string(guild_ranks_entry.can_warpeace));

			insert_chunks.push_back("(" + implode(",", insert_values) + ")");
		}

		std::vector<std::string> insert_values;

		auto results = database.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<GuildRanks> All()
	{
		std::vector<GuildRanks> all_entries;

		auto results = database.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			GuildRanks entry{};

			entry.guild_id     = atoi(row[0]);
			entry.rank         = atoi(row[1]);
			entry.title        = row[2];
			entry.can_hear     = atoi(row[3]);
			entry.can_speak    = atoi(row[4]);
			entry.can_invite   = atoi(row[5]);
			entry.can_remove   = atoi(row[6]);
			entry.can_promote  = atoi(row[7]);
			entry.can_demote   = atoi(row[8]);
			entry.can_motd     = atoi(row[9]);
			entry.can_warpeace = atoi(row[10]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

};

#endif //EQEMU_GUILD_RANKS_REPOSITORY_H
