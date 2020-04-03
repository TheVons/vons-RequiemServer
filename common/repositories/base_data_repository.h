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

#ifndef EQEMU_BASE_DATA_REPOSITORY_H
#define EQEMU_BASE_DATA_REPOSITORY_H

#include "../database.h"
#include "../string_util.h"

class BaseDataRepository {
public:
	struct BaseData {
		int level;
		int class;
		std::string hp;
		std::string mana;
		std::string end;
		std::string unk1;
		std::string unk2;
		std::string hp_fac;
		std::string mana_fac;
		std::string end_fac;
	};

	static std::string PrimaryKey()
	{
		return std::string("class");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"level",
			"class",
			"hp",
			"mana",
			"end",
			"unk1",
			"unk2",
			"hp_fac",
			"mana_fac",
			"end_fac",
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
		return std::string("base_data");
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

	static BaseData NewEntity()
	{
		BaseData entry{};

		entry.level = 0;
		entry.
		class    = 0;
		entry.hp       = 0;
		entry.mana     = 0;
		entry.end      = 0;
		entry.unk1     = 0;
		entry.unk2     = 0;
		entry.hp_fac   = 0;
		entry.mana_fac = 0;
		entry.end_fac  = 0;

		return entry;
	}

	static BaseData GetBaseDataEntry(
		const std::vector<BaseData> &base_datas,
		int base_data_id
	)
	{
		for (auto &base_data : base_datas) {
			if (base_data. { class }== base_data_id) {
				return base_data;
			}
		}

		return NewEntity();
	}

	static BaseData FindOne(
		int base_data_id
	)
	{
		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				base_data_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			BaseData entry{};

			entry.level = atoi(row[0]);
			entry.
			class    = atoi(row[1]);
			entry.hp       = atof(row[2]);
			entry.mana     = atof(row[3]);
			entry.end      = atof(row[4]);
			entry.unk1     = atof(row[5]);
			entry.unk2     = atof(row[6]);
			entry.hp_fac   = atof(row[7]);
			entry.mana_fac = atof(row[8]);
			entry.end_fac  = atof(row[9]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		int base_data_id
	)
	{
		auto results = content_db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				base_data_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		BaseData base_data_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[2] + " = '" + EscapeString(base_data_entry.hp) + "'");
		update_values.push_back(columns[3] + " = '" + EscapeString(base_data_entry.mana) + "'");
		update_values.push_back(columns[4] + " = '" + EscapeString(base_data_entry.end) + "'");
		update_values.push_back(columns[5] + " = '" + EscapeString(base_data_entry.unk1) + "'");
		update_values.push_back(columns[6] + " = '" + EscapeString(base_data_entry.unk2) + "'");
		update_values.push_back(columns[7] + " = '" + EscapeString(base_data_entry.hp_fac) + "'");
		update_values.push_back(columns[8] + " = '" + EscapeString(base_data_entry.mana_fac) + "'");
		update_values.push_back(columns[9] + " = '" + EscapeString(base_data_entry.end_fac) + "'");

		auto
		results = content_db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				implode(", ", update_values),
				PrimaryKey(),
				base_data_entry.
		class
		)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static BaseData InsertOne(
		BaseData base_data_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back("'" + EscapeString(base_data_entry.hp) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.mana) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.end) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.unk1) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.unk2) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.hp_fac) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.mana_fac) + "'");
		insert_values.push_back("'" + EscapeString(base_data_entry.end_fac) + "'");

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				implode(",", insert_values)
			)
		);

		if (results.Success()) {
			base_data_entry.id = results.LastInsertedID();
			return base_data_entry;
		}

		base_data_entry = InstanceListRepository::NewEntity();

		return base_data_entry;
	}

	static int InsertMany(
		std::vector<BaseData> base_data_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &base_data_entry: base_data_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back("'" + EscapeString(base_data_entry.hp) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.mana) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.end) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.unk1) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.unk2) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.hp_fac) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.mana_fac) + "'");
			insert_values.push_back("'" + EscapeString(base_data_entry.end_fac) + "'");

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

	static std::vector<BaseData> All()
	{
		std::vector<BaseData> all_entries;

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			BaseData entry{};

			entry.level = atoi(row[0]);
			entry.
			class    = atoi(row[1]);
			entry.hp       = atof(row[2]);
			entry.mana     = atof(row[3]);
			entry.end      = atof(row[4]);
			entry.unk1     = atof(row[5]);
			entry.unk2     = atof(row[6]);
			entry.hp_fac   = atof(row[7]);
			entry.mana_fac = atof(row[8]);
			entry.end_fac  = atof(row[9]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

};

#endif //EQEMU_BASE_DATA_REPOSITORY_H
