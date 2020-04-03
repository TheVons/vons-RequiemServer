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

#ifndef EQEMU_DOORS_REPOSITORY_H
#define EQEMU_DOORS_REPOSITORY_H

#include "../database.h"
#include "../string_util.h"

class DoorsRepository {
public:
	struct Doors {
		int         id;
		int16       doorid;
		std::string zone;
		int16       version;
		std::string name;
		std::string pos_y;
		std::string pos_x;
		std::string pos_z;
		std::string heading;
		int16       opentype;
		int16       guild;
		int16       lockpick;
		int         keyitem;
		int8        nokeyring;
		int16       triggerdoor;
		int16       triggertype;
		int8        disable_timer;
		int16       doorisopen;
		int         door_param;
		std::string dest_zone;
		int         dest_instance;
		std::string dest_x;
		std::string dest_y;
		std::string dest_z;
		std::string dest_heading;
		int         invert_state;
		int         incline;
		int16       size;
		std::string buffer;
		int         client_version_mask;
		int16       is_ldon_door;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"doorid",
			"zone",
			"version",
			"name",
			"pos_y",
			"pos_x",
			"pos_z",
			"heading",
			"opentype",
			"guild",
			"lockpick",
			"keyitem",
			"nokeyring",
			"triggerdoor",
			"triggertype",
			"disable_timer",
			"doorisopen",
			"door_param",
			"dest_zone",
			"dest_instance",
			"dest_x",
			"dest_y",
			"dest_z",
			"dest_heading",
			"invert_state",
			"incline",
			"size",
			"buffer",
			"client_version_mask",
			"is_ldon_door",
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
		return std::string("doors");
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

	static Doors NewEntity()
	{
		Doors entry{};

		entry.id                  = 0;
		entry.doorid              = 0;
		entry.zone                = 0;
		entry.version             = 0;
		entry.name                = "";
		entry.pos_y               = 0;
		entry.pos_x               = 0;
		entry.pos_z               = 0;
		entry.heading             = 0;
		entry.opentype            = 0;
		entry.guild               = 0;
		entry.lockpick            = 0;
		entry.keyitem             = 0;
		entry.nokeyring           = 0;
		entry.triggerdoor         = 0;
		entry.triggertype         = 0;
		entry.disable_timer       = 0;
		entry.doorisopen          = 0;
		entry.door_param          = 0;
		entry.dest_zone           = 'NONE';
		entry.dest_instance       = 0;
		entry.dest_x              = 0;
		entry.dest_y              = 0;
		entry.dest_z              = 0;
		entry.dest_heading        = 0;
		entry.invert_state        = 0;
		entry.incline             = 0;
		entry.size                = 100;
		entry.buffer              = 0;
		entry.client_version_mask = 4294967295;
		entry.is_ldon_door        = 0;

		return entry;
	}

	static Doors GetDoorsEntry(
		const std::vector<Doors> &doorss,
		int doors_id
	)
	{
		for (auto &doors : doorss) {
			if (doors.id == doors_id) {
				return doors;
			}
		}

		return NewEntity();
	}

	static Doors FindOne(
		int doors_id
	)
	{
		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} WHERE id = {} LIMIT 1",
				BaseSelect(),
				doors_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			Doors entry{};

			entry.id                  = atoi(row[0]);
			entry.doorid              = atoi(row[1]);
			entry.zone                = row[2];
			entry.version             = atoi(row[3]);
			entry.name                = row[4];
			entry.pos_y               = atof(row[5]);
			entry.pos_x               = atof(row[6]);
			entry.pos_z               = atof(row[7]);
			entry.heading             = atof(row[8]);
			entry.opentype            = atoi(row[9]);
			entry.guild               = atoi(row[10]);
			entry.lockpick            = atoi(row[11]);
			entry.keyitem             = atoi(row[12]);
			entry.nokeyring           = atoi(row[13]);
			entry.triggerdoor         = atoi(row[14]);
			entry.triggertype         = atoi(row[15]);
			entry.disable_timer       = atoi(row[16]);
			entry.doorisopen          = atoi(row[17]);
			entry.door_param          = atoi(row[18]);
			entry.dest_zone           = row[19];
			entry.dest_instance       = atoi(row[20]);
			entry.dest_x              = atof(row[21]);
			entry.dest_y              = atof(row[22]);
			entry.dest_z              = atof(row[23]);
			entry.dest_heading        = atof(row[24]);
			entry.invert_state        = atoi(row[25]);
			entry.incline             = atoi(row[26]);
			entry.size                = atoi(row[27]);
			entry.buffer              = atof(row[28]);
			entry.client_version_mask = atoi(row[29]);
			entry.is_ldon_door        = atoi(row[30]);

			return entry;
		}

		return NewEntity();
	}

	static int DeleteOne(
		int doors_id
	)
	{
		auto results = content_db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				doors_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Doors doors_entry
	)
	{
		std::vector<std::string> update_values;

		auto columns = Columns();

		update_values.push_back(columns[1] + " = " + std::to_string(doors_entry.doorid));
		update_values.push_back(columns[2] + " = '" + EscapeString(doors_entry.zone) + "'");
		update_values.push_back(columns[3] + " = " + std::to_string(doors_entry.version));
		update_values.push_back(columns[4] + " = '" + EscapeString(doors_entry.name) + "'");
		update_values.push_back(columns[5] + " = '" + EscapeString(doors_entry.pos_y) + "'");
		update_values.push_back(columns[6] + " = '" + EscapeString(doors_entry.pos_x) + "'");
		update_values.push_back(columns[7] + " = '" + EscapeString(doors_entry.pos_z) + "'");
		update_values.push_back(columns[8] + " = '" + EscapeString(doors_entry.heading) + "'");
		update_values.push_back(columns[9] + " = " + std::to_string(doors_entry.opentype));
		update_values.push_back(columns[10] + " = " + std::to_string(doors_entry.guild));
		update_values.push_back(columns[11] + " = " + std::to_string(doors_entry.lockpick));
		update_values.push_back(columns[12] + " = " + std::to_string(doors_entry.keyitem));
		update_values.push_back(columns[13] + " = " + std::to_string(doors_entry.nokeyring));
		update_values.push_back(columns[14] + " = " + std::to_string(doors_entry.triggerdoor));
		update_values.push_back(columns[15] + " = " + std::to_string(doors_entry.triggertype));
		update_values.push_back(columns[16] + " = " + std::to_string(doors_entry.disable_timer));
		update_values.push_back(columns[17] + " = " + std::to_string(doors_entry.doorisopen));
		update_values.push_back(columns[18] + " = " + std::to_string(doors_entry.door_param));
		update_values.push_back(columns[19] + " = '" + EscapeString(doors_entry.dest_zone) + "'");
		update_values.push_back(columns[20] + " = " + std::to_string(doors_entry.dest_instance));
		update_values.push_back(columns[21] + " = '" + EscapeString(doors_entry.dest_x) + "'");
		update_values.push_back(columns[22] + " = '" + EscapeString(doors_entry.dest_y) + "'");
		update_values.push_back(columns[23] + " = '" + EscapeString(doors_entry.dest_z) + "'");
		update_values.push_back(columns[24] + " = '" + EscapeString(doors_entry.dest_heading) + "'");
		update_values.push_back(columns[25] + " = " + std::to_string(doors_entry.invert_state));
		update_values.push_back(columns[26] + " = " + std::to_string(doors_entry.incline));
		update_values.push_back(columns[27] + " = " + std::to_string(doors_entry.size));
		update_values.push_back(columns[28] + " = '" + EscapeString(doors_entry.buffer) + "'");
		update_values.push_back(columns[29] + " = " + std::to_string(doors_entry.client_version_mask));
		update_values.push_back(columns[30] + " = " + std::to_string(doors_entry.is_ldon_door));

		auto results = content_db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				implode(", ", update_values),
				PrimaryKey(),
				doors_entry.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static Doors InsertOne(
		Doors doors_entry
	)
	{
		std::vector<std::string> insert_values;

		insert_values.push_back(std::to_string(doors_entry.doorid));
		insert_values.push_back("'" + EscapeString(doors_entry.zone) + "'");
		insert_values.push_back(std::to_string(doors_entry.version));
		insert_values.push_back("'" + EscapeString(doors_entry.name) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.pos_y) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.pos_x) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.pos_z) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.heading) + "'");
		insert_values.push_back(std::to_string(doors_entry.opentype));
		insert_values.push_back(std::to_string(doors_entry.guild));
		insert_values.push_back(std::to_string(doors_entry.lockpick));
		insert_values.push_back(std::to_string(doors_entry.keyitem));
		insert_values.push_back(std::to_string(doors_entry.nokeyring));
		insert_values.push_back(std::to_string(doors_entry.triggerdoor));
		insert_values.push_back(std::to_string(doors_entry.triggertype));
		insert_values.push_back(std::to_string(doors_entry.disable_timer));
		insert_values.push_back(std::to_string(doors_entry.doorisopen));
		insert_values.push_back(std::to_string(doors_entry.door_param));
		insert_values.push_back("'" + EscapeString(doors_entry.dest_zone) + "'");
		insert_values.push_back(std::to_string(doors_entry.dest_instance));
		insert_values.push_back("'" + EscapeString(doors_entry.dest_x) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.dest_y) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.dest_z) + "'");
		insert_values.push_back("'" + EscapeString(doors_entry.dest_heading) + "'");
		insert_values.push_back(std::to_string(doors_entry.invert_state));
		insert_values.push_back(std::to_string(doors_entry.incline));
		insert_values.push_back(std::to_string(doors_entry.size));
		insert_values.push_back("'" + EscapeString(doors_entry.buffer) + "'");
		insert_values.push_back(std::to_string(doors_entry.client_version_mask));
		insert_values.push_back(std::to_string(doors_entry.is_ldon_door));

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				implode(",", insert_values)
			)
		);

		if (results.Success()) {
			doors_entry.id = results.LastInsertedID();
			return doors_entry;
		}

		doors_entry = InstanceListRepository::NewEntity();

		return doors_entry;
	}

	static int InsertMany(
		std::vector<Doors> doors_entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &doors_entry: doors_entries) {
			std::vector<std::string> insert_values;

			insert_values.push_back(std::to_string(doors_entry.doorid));
			insert_values.push_back("'" + EscapeString(doors_entry.zone) + "'");
			insert_values.push_back(std::to_string(doors_entry.version));
			insert_values.push_back("'" + EscapeString(doors_entry.name) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.pos_y) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.pos_x) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.pos_z) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.heading) + "'");
			insert_values.push_back(std::to_string(doors_entry.opentype));
			insert_values.push_back(std::to_string(doors_entry.guild));
			insert_values.push_back(std::to_string(doors_entry.lockpick));
			insert_values.push_back(std::to_string(doors_entry.keyitem));
			insert_values.push_back(std::to_string(doors_entry.nokeyring));
			insert_values.push_back(std::to_string(doors_entry.triggerdoor));
			insert_values.push_back(std::to_string(doors_entry.triggertype));
			insert_values.push_back(std::to_string(doors_entry.disable_timer));
			insert_values.push_back(std::to_string(doors_entry.doorisopen));
			insert_values.push_back(std::to_string(doors_entry.door_param));
			insert_values.push_back("'" + EscapeString(doors_entry.dest_zone) + "'");
			insert_values.push_back(std::to_string(doors_entry.dest_instance));
			insert_values.push_back("'" + EscapeString(doors_entry.dest_x) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.dest_y) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.dest_z) + "'");
			insert_values.push_back("'" + EscapeString(doors_entry.dest_heading) + "'");
			insert_values.push_back(std::to_string(doors_entry.invert_state));
			insert_values.push_back(std::to_string(doors_entry.incline));
			insert_values.push_back(std::to_string(doors_entry.size));
			insert_values.push_back("'" + EscapeString(doors_entry.buffer) + "'");
			insert_values.push_back(std::to_string(doors_entry.client_version_mask));
			insert_values.push_back(std::to_string(doors_entry.is_ldon_door));

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

	static std::vector<Doors> All()
	{
		std::vector<Doors> all_entries;

		auto results = content_db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			Doors entry{};

			entry.id                  = atoi(row[0]);
			entry.doorid              = atoi(row[1]);
			entry.zone                = row[2];
			entry.version             = atoi(row[3]);
			entry.name                = row[4];
			entry.pos_y               = atof(row[5]);
			entry.pos_x               = atof(row[6]);
			entry.pos_z               = atof(row[7]);
			entry.heading             = atof(row[8]);
			entry.opentype            = atoi(row[9]);
			entry.guild               = atoi(row[10]);
			entry.lockpick            = atoi(row[11]);
			entry.keyitem             = atoi(row[12]);
			entry.nokeyring           = atoi(row[13]);
			entry.triggerdoor         = atoi(row[14]);
			entry.triggertype         = atoi(row[15]);
			entry.disable_timer       = atoi(row[16]);
			entry.doorisopen          = atoi(row[17]);
			entry.door_param          = atoi(row[18]);
			entry.dest_zone           = row[19];
			entry.dest_instance       = atoi(row[20]);
			entry.dest_x              = atof(row[21]);
			entry.dest_y              = atof(row[22]);
			entry.dest_z              = atof(row[23]);
			entry.dest_heading        = atof(row[24]);
			entry.invert_state        = atoi(row[25]);
			entry.incline             = atoi(row[26]);
			entry.size                = atoi(row[27]);
			entry.buffer              = atof(row[28]);
			entry.client_version_mask = atoi(row[29]);
			entry.is_ldon_door        = atoi(row[30]);

			all_entries.push_back(entry);
		}

		return all_entries;
	}

};

#endif //EQEMU_DOORS_REPOSITORY_H
