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

#ifndef EQEMU_SPAWN2_REPOSITORY_H
#define EQEMU_SPAWN2_REPOSITORY_H

#include "../database.h"
#include "../string_util.h"

class Spawn2Repository {
public:
	struct Spawn2 {
		int         id;
		int         spawngroupID;
		std::string zone;
		int16       version;
		std::string x;
		std::string y;
		std::string z;
		std::string heading;
		int         respawntime;
		int         variance;
		int         pathgrid;
		int         _condition;
		int         cond_value;
		int8        enabled;
		int8        animation;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"spawngroupID",
			"zone",
			"version",
			"x",
			"y",
			"z",
			"heading",
			"respawntime",
			"variance",
			"pathgrid",
			"_condition",
			"cond_value",
			"enabled",
			"animation",
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
		return std::string("spawn2");
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

	static Spawn2 NewEntity()
	{
		Spawn2 entry{};

		entry.id           = 0;
		entry.spawngroupID = 0;
		entry.zone         = 0;
		entry.version      = 0;
		entry.x            = 0.000000;
		entry.y            = 0.000000;
		entry.z            = 0.000000;
		entry.heading      = 0.000000;
		entry.respawntime  = 0;
		entry.variance     = 0;
		entry.pathgrid     = 0;
		entry._condition   = 0;
		entry.cond_value   = 1;
		entry.enabled      = 1;
		entry.animation    = 0;

		return entry;
	}

	static Spawn2 GetSpawn2Entry(
		const std::vector<Spawn2> &spawn2s,
		int spawn2_id
	)
	{
		for (auto &spawn2 : spawn2s) {
			if (spawn2.id == spawn2_id) {
				return spawn2;
			}
		}

		return NewEntity();
	}

	static Spawn2 FindOne(
		int spawn2_id
	)
	{
		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				spawn2_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			Spawn2 entry{};

			entry.id           = atoi(row[0]);
			entry.spawngroupID = atoi(row[1]);
			entry.zone         = row[2];
			entry.version      = atoi(row[3]);
			entry.x            = atof(row[4]);
			entry.y            = atof(row[5]);
			entry.z            = atof(row[6]);
			entry.heading      = atof(row[7]);
			entry.respawntime  = atoi(row[8]);
			entry.variance     = atoi(row[9]);
			entry.pathgrid     = atoi(row[10]);
			entry._condition   = atoi(row[11]);
			entry.cond_value   = atoi(row[12]);
			entry.enabled      = atoi(row[13]);
			entry.animation    = atoi(row[14]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		int spawn2_id
	)
	{
		auto results = content_db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				spawn2_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Spawn2 spawn2_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[1] + " = " + std::to_string(spawn2_entry.spawngroupID));
		update_values.push_back(columns[2] + " = '" + EscapeString(spawn2_entry.zone) + "'");
		update_values.push_back(columns[3] + " = " + std::to_string(spawn2_entry.version));
		update_values.push_back(columns[4] + " = '" + EscapeString(spawn2_entry.x) + "'");
		update_values.push_back(columns[5] + " = '" + EscapeString(spawn2_entry.y) + "'");
		update_values.push_back(columns[6] + " = '" + EscapeString(spawn2_entry.z) + "'");
		update_values.push_back(columns[7] + " = '" + EscapeString(spawn2_entry.heading) + "'");
		update_values.push_back(columns[8] + " = " + std::to_string(spawn2_entry.respawntime));
		update_values.push_back(columns[9] + " = " + std::to_string(spawn2_entry.variance));
		update_values.push_back(columns[10] + " = " + std::to_string(spawn2_entry.pathgrid));
		update_values.push_back(columns[11] + " = " + std::to_string(spawn2_entry._condition));
		update_values.push_back(columns[12] + " = " + std::to_string(spawn2_entry.cond_value));
		update_values.push_back(columns[13] + " = " + std::to_string(spawn2_entry.enabled));
		update_values.push_back(columns[14] + " = " + std::to_string(spawn2_entry.animation));

		auto results = content_db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				implode(", ", update_values),
				PrimaryKey(),
				spawn2_entry.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static Spawn2 InsertOne(
		Spawn2 spawn2_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(spawn2_entry.spawngroupID));
		insert_values.push_back("'" + EscapeString(spawn2_entry.zone) + "'");
		insert_values.push_back(std::to_string(spawn2_entry.version));
		insert_values.push_back("'" + EscapeString(spawn2_entry.x) + "'");
		insert_values.push_back("'" + EscapeString(spawn2_entry.y) + "'");
		insert_values.push_back("'" + EscapeString(spawn2_entry.z) + "'");
		insert_values.push_back("'" + EscapeString(spawn2_entry.heading) + "'");
		insert_values.push_back(std::to_string(spawn2_entry.respawntime));
		insert_values.push_back(std::to_string(spawn2_entry.variance));
		insert_values.push_back(std::to_string(spawn2_entry.pathgrid));
		insert_values.push_back(std::to_string(spawn2_entry._condition));
		insert_values.push_back(std::to_string(spawn2_entry.cond_value));
		insert_values.push_back(std::to_string(spawn2_entry.enabled));
		insert_values.push_back(std::to_string(spawn2_entry.animation));

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				implode(",", insert_values)
			)
		);

		if (results.Success()) {
			spawn2_entry.id = results.LastInsertedID();
			return spawn2_entry;
		}

		spawn2_entry = InstanceListRepository::NewEntity();

		return spawn2_entry;
	}

	static int InsertMany(
		std::vector<Spawn2> spawn2_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &spawn2_entry: spawn2_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(spawn2_entry.spawngroupID));
			insert_values.push_back("'" + EscapeString(spawn2_entry.zone) + "'");
			insert_values.push_back(std::to_string(spawn2_entry.version));
			insert_values.push_back("'" + EscapeString(spawn2_entry.x) + "'");
			insert_values.push_back("'" + EscapeString(spawn2_entry.y) + "'");
			insert_values.push_back("'" + EscapeString(spawn2_entry.z) + "'");
			insert_values.push_back("'" + EscapeString(spawn2_entry.heading) + "'");
			insert_values.push_back(std::to_string(spawn2_entry.respawntime));
			insert_values.push_back(std::to_string(spawn2_entry.variance));
			insert_values.push_back(std::to_string(spawn2_entry.pathgrid));
			insert_values.push_back(std::to_string(spawn2_entry._condition));
			insert_values.push_back(std::to_string(spawn2_entry.cond_value));
			insert_values.push_back(std::to_string(spawn2_entry.enabled));
			insert_values.push_back(std::to_string(spawn2_entry.animation));

			insert_chunks.push_back("(" + implode(",", insert_values) + ")");
		}

		std::vector<std::string> insert_values;

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<Spawn2> All()
	{
		std::vector<Spawn2> all_entries;

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Spawn2 entry{};

			entry.id           = atoi(row[0]);
			entry.spawngroupID = atoi(row[1]);
			entry.zone         = row[2];
			entry.version      = atoi(row[3]);
			entry.x            = atof(row[4]);
			entry.y            = atof(row[5]);
			entry.z            = atof(row[6]);
			entry.heading      = atof(row[7]);
			entry.respawntime  = atoi(row[8]);
			entry.variance     = atoi(row[9]);
			entry.pathgrid     = atoi(row[10]);
			entry._condition   = atoi(row[11]);
			entry.cond_value   = atoi(row[12]);
			entry.enabled      = atoi(row[13]);
			entry.animation    = atoi(row[14]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

};

#endif //EQEMU_SPAWN2_REPOSITORY_H
