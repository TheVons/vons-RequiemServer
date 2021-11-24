#include "../common/features.h"

#ifdef EMBPERL_XS_CLASSES

#include "../common/global_define.h"
#include "embperl.h"

#ifdef seed
#undef seed
#endif

typedef const char Const_char;

#include "mob.h"
#include "client.h"
#include "../common/spdat.h"
#include "dialogue_window.h"

#ifdef BOTS
#include "bot.h"
#endif

#ifdef THIS /* this macro seems to leak out on some systems */
#undef THIS
#endif

#define VALIDATE_THIS_IS_MOB \
	do { \
		if (sv_derived_from(ST(0), "Mob")) { \
			IV tmp = SvIV((SV*)SvRV(ST(0))); \
			THIS = INT2PTR(Mob*, tmp); \
		} else { \
			Perl_croak(aTHX_ "THIS is not of type Mob"); \
		} \
		if (THIS == nullptr) { \
			Perl_croak(aTHX_ "THIS is nullptr, avoiding crash."); \
		} \
	} while (0);

XS(XS_Mob_IsClient); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsClient) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsClient(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsClient();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsNPC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsNPC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsNPC(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsNPC();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsBot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsBot) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsBot(THIS)"); // @categories Script Utility
	{
		Mob* THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsBot();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsMob); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsMob) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsMob(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsMob();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsCorpse); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsCorpse) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsCorpse(THIS)"); // @categories Script Utility, Corpse
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsCorpse();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsPlayerCorpse); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsPlayerCorpse) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsPlayerCorpse(THIS)"); // @categories Corpse
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsPlayerCorpse();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsNPCCorpse); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsNPCCorpse) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsNPCCorpse(THIS)"); // @categories Corpse
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsNPCCorpse();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsObject); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsObject) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsObject(THIS)"); // @categories Objects
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsObject();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsDoor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsDoor) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsDoor(THIS)"); // @categories Script Utility, Doors
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsDoor();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsTrap); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsTrap) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsTrap(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsTrap();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsBeacon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsBeacon) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsBeacon(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsBeacon();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CastToClient); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastToClient) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CastToClient(THIS)"); // @categories Account and Character, Script Utility
	{
		Mob    *THIS;
		Client *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CastToClient();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Client", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_CastToNPC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastToNPC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CastToNPC(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		NPC *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CastToNPC();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "NPC", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_CastToMob); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastToMob) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CastToMob(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CastToMob();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_CastToCorpse); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastToCorpse) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CastToCorpse(THIS)"); // @categories Script Utility, Corpse
	{
		Mob    *THIS;
		Corpse *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CastToCorpse();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Corpse", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetID(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetName); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetName) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetName(THIS)"); // @categories Script Utility
	{
		Mob        *THIS;
		Const_char *RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetName();
		sv_setpv(TARG, RETVAL);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_Depop); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Depop) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Mob::Depop(THIS, StartSpawnTimer = true)"); // @categories Spawns
	{
		Mob *THIS;
		bool StartSpawnTimer;
		VALIDATE_THIS_IS_MOB;
		if (items < 2)
			StartSpawnTimer = true;
		else {
			StartSpawnTimer = (bool) SvTRUE(ST(1));
		}

		THIS->Depop(StartSpawnTimer);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_RogueAssassinate); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RogueAssassinate) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::RogueAssassinate(THIS, other)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		THIS->RogueAssassinate(other);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_BehindMob); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_BehindMob) {
	dXSARGS;
	if (items < 1 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::BehindMob(THIS, Mob* other = 0, [float x = 0.0f], [float y= 0.0f])"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		Mob *other;
		float playerx;
		float playery;
		VALIDATE_THIS_IS_MOB;
		if (items < 2)
			other = 0;
		else {
			if (sv_derived_from(ST(1), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(1)));
				other = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "other is not of type Mob");
			if (other == nullptr)
				Perl_croak(aTHX_ "other is nullptr, avoiding crash.");
		}

		if (items < 3)
			playerx = 0.0f;
		else {
			playerx = (float) SvNV(ST(2));
		}

		if (items < 4)
			playery = 0.0f;
		else {
			playery = (float) SvNV(ST(3));
		}

		RETVAL = THIS->BehindMob(other, playerx, playery);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SetLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetLevel) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::SetLevel(THIS, uint8 in_level, [bool command = false])"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 in_level = (uint8) SvUV(ST(1));
		bool  command;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			command = false;
		else {
			command = (bool) SvTRUE(ST(2));
		}

		THIS->SetLevel(in_level, command);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetSkill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSkill) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetSkill(THIS, int skill_id)"); // @categories Skills and Recipes, Script Utility
	{
		Mob *THIS;
		uint32                   RETVAL;
		dXSTARG;
		EQ::skills::SkillType skill_num = (EQ::skills::SkillType) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSkill(skill_num);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SendWearChange); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SendWearChange) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SendWearChange(THIS, uint8 material_slot)"); // @categories Script Utility
	{
		Mob *THIS;
		uint8 material_slot = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SendWearChange(material_slot);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetEquipment); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetEquipment) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetEquipment(THIS, uint8 material_slot)"); // @categories Inventory and Items
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		uint8 material_slot = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetEquippedItemFromTextureSlot(material_slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetEquipmentMaterial); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetEquipmentMaterial) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetEquipmentMaterial(THIS, uint8 material_slot)"); // @categories Inventory and Items
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		uint8 material_slot = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetEquipmentMaterial(material_slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetEquipmentColor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetEquipmentColor) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetEquipmentColor(THIS, uint8 material_slot)"); // @categories Inventory and Items
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		uint8 material_slot = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetEquipmentColor(material_slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetArmorTint); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetArmorTint) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetArmorTint(THIS, uint8 material_slot)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		uint8 material_slot = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetArmorTint(material_slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsMoving); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsMoving) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsMoving(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsMoving();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GoToBind); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GoToBind) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GoToBind(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->GoToBind();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Gate); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Gate) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::Gate(THIS)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->Gate();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Attack); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Attack) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::Attack(THIS, Mob* other, [int hand = 13 [prim|sec]], [bool from_riposte = false])"); // @categories Script Utility, Hate and Aggro
	{
		Mob *THIS;
		bool RETVAL;
		Mob *other;
		int  Hand;
		bool FromRiposte;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		if (items < 3)
			Hand = 13;
		else {
			Hand = (int) SvIV(ST(2));
		}

		if (items < 4)
			FromRiposte = false;
		else {
			FromRiposte = (bool) SvTRUE(ST(3));
		}

		RETVAL = THIS->Attack(other, Hand, FromRiposte);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_Damage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Damage) {
	dXSARGS;
	if (items < 5 || items > 8)
		Perl_croak(aTHX_ "Usage: Mob::Damage(THIS, Mob* from, int32 damage, uint16 spell_id, int attack_skill, [bool avoidable = true], [int8 buffslot = -1], [bool buff_tic = false])"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *from;
		int32                    damage       = (int32) SvIV(ST(2));
		uint16                   spell_id     = (uint16) SvUV(ST(3));
		EQ::skills::SkillType attack_skill = (EQ::skills::SkillType) SvUV(ST(4));
		bool                     avoidable;
		int8                     buffslot;
		bool                     iBuffTic;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			from = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "from is not of type Mob");
		if (from == nullptr)
			Perl_croak(aTHX_ "from is nullptr, avoiding crash.");

		if (items < 6)
			avoidable = true;
		else {
			avoidable = (bool) SvTRUE(ST(5));
		}

		if (items < 7)
			buffslot = -1;
		else {
			buffslot = (int8) SvIV(ST(6));
		}

		if (items < 8)
			iBuffTic = false;
		else {
			iBuffTic = (bool) SvTRUE(ST(7));
		}

		THIS->Damage(from, damage, spell_id, attack_skill, avoidable, buffslot, iBuffTic);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_RangedAttack); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RangedAttack) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::RangedAttack(THIS, Mob* other)"); // @categories Skills and Recipes, Script Utility
	{
		Mob *THIS;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		THIS->RangedAttack(other);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ThrowingAttack); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ThrowingAttack) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::ThrowingAttack(THIS, Mob* other)"); // @categories Skills and Recipes, Script Utility
	{
		Mob *THIS;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		THIS->ThrowingAttack(other);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Heal); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Heal) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::Heal(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->Heal();
	}
	XSRETURN_EMPTY;
}


XS(XS_Mob_HealDamage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_HealDamage) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::HealDamage(THIS, int32 amount, [Mob* caster = 0])"); // @categories Script Utility
	{
		Mob *THIS;
		int32 heal_amt = (int32) SvIV(ST(1));
		Mob *caster = nullptr;
		VALIDATE_THIS_IS_MOB;
		if (items == 3) {
			if (sv_derived_from(ST(2), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(2)));
				caster = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "caster is not of type Mob");
			if (caster == nullptr)
				Perl_croak(aTHX_ "caster is nullptr, avoiding crash.");
		}

		THIS->HealDamage(heal_amt, caster);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetMaxHP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetMaxHP) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::SetMaxHP(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->SetMaxHP();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetLevelCon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetLevelCon) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetLevelCon(THIS, uint8 other_level)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint8  iOtherLevel = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetLevelCon(iOtherLevel);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetHP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetHP) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetHP(THIS, int32 hp)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 hp = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetHP(hp);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DoAnim); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DoAnim) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::DoAnim(THIS, int animation_number, [int type = 0])"); // @categories Script Utility
	{
		Mob *THIS;
		int animnum = (int) SvIV(ST(1));
		int type;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			type = 0;
		else {
			type = (int) SvIV(ST(2));
		}

		THIS->DoAnim(animnum, type);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ChangeSize); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ChangeSize) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::ChangeSize(THIS, float in_size, [bool no_restriction = false])"); // @categories Script Utility
	{
		Mob *THIS;
		float in_size = (float) SvNV(ST(1));
		bool  bNoRestriction;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			bNoRestriction = false;
		else {
			bNoRestriction = (bool) SvTRUE(ST(2));
		}

		THIS->ChangeSize(in_size, bNoRestriction);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_RandomizeFeatures); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RandomizeFeatures) {
		dXSARGS;
		if (items < 2 || items > 3)
			Perl_croak(aTHX_ "Usage: Mob::RandomizeFeatures(THIS, bool send_illusion, set_variables)"); // @categories Script Utility
		{
			Mob *THIS;
			bool send_illusion = (bool) SvNV(ST(1));
            bool set_variables = (bool) SvNV(ST(2));
			VALIDATE_THIS_IS_MOB;
			THIS->RandomizeFeatures(send_illusion, set_variables);
		}
		XSRETURN_EMPTY;
}

XS(XS_Mob_GMMove); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GMMove) {
	dXSARGS;
	if (items < 4 || items > 5)
		Perl_croak(aTHX_ "Usage: Mob::GMMove(THIS, float x, float y, float z, [float heading = 0.01])"); // @categories Script Utility
	{
		Mob *THIS;
		float x = (float) SvNV(ST(1));
		float y = (float) SvNV(ST(2));
		float z = (float) SvNV(ST(3));
		float heading;
		VALIDATE_THIS_IS_MOB;
		if (items < 5)
			heading = 0.01;
		else {
			heading = (float) SvNV(ST(4));
		}

		THIS->GMMove(x, y, z, heading);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_HasProcs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_HasProcs) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HasProcs(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasProcs();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsInvisible); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsInvisible) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Mob::IsInvisible(THIS, [Mob* other = 0])"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (items < 2)
			other = 0;
		else {
			if (sv_derived_from(ST(1), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(1)));
				other = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "other is not of type Mob");
			if (other == nullptr)
				Perl_croak(aTHX_ "other is nullptr, avoiding crash.");
		}

		RETVAL = THIS->IsInvisible(other);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SetInvisible); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetInvisible) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetInvisible(THIS, uint8 state)"); // @categories Script Utility
	{
		Mob *THIS;
		uint8 state = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetInvisible(state);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_FindBuff); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_FindBuff) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::FindBuff(THIS, uint16 spell_id)"); // @categories Spells and Disciplines, Script Utility
	{
		Mob *THIS;
		bool   RETVAL;
		uint16 spellid = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->FindBuff(spellid);
		ST(0)          = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_FindBuffBySlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_FindBuffBySlot) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::FindBuffBySlot(THIS, int slot)"); // @categories Spells and Disciplines, Script Utility
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		int slot = SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->FindBuffBySlot(slot);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_BuffCount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_BuffCount) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::BuffCount(THIS)"); // @categories Script Utility, Spells and Disciplines
	{
		Mob *THIS;
		uint32  RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->BuffCount();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_FindType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_FindType) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::FindType(THIS, uint8 type, [bool offensive = false], [uint16 threshold = 100])"); // @categories Script Utility
	{
		Mob *THIS;
		bool   RETVAL;
		uint8  type = (uint8) SvUV(ST(1));
		bool   bOffensive;
		uint16 threshold;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			bOffensive = false;
		else {
			bOffensive = (bool) SvTRUE(ST(2));
		}

		if (items < 4)
			threshold = 100;
		else {
			threshold = (uint16) SvUV(ST(3));
		}

		RETVAL = THIS->FindType(type, bOffensive, threshold);
		ST(0)       = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBuffSlotFromType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetBuffSlotFromType) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetBuffSlotFromType(THIS, uint16 type)"); // @categories Spells and Disciplines, Script Utility
	{
		Mob *THIS;
		int8   RETVAL;
		dXSTARG;
		uint16 type = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBuffSlotFromType(type);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_MakePet); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_MakePet) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::MakePet(THIS, uint16 spell_id, string pet_type, [string name = nullptr])"); // @categories Pet
	{
		Mob *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		char *pettype = (char *) SvPV_nolen(ST(2));
		char *name;
		VALIDATE_THIS_IS_MOB;
		if (items < 4)
			name = nullptr;
		else {
			name = (char *) SvPV_nolen(ST(3));
		}

		THIS->MakePet(spell_id, pettype, name);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_MakeTempPet); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_MakeTempPet) {
	dXSARGS;
	if (items < 2 || items > 6)
		Perl_croak(aTHX_ "Usage: Mob::MakeTempPet(THIS, uint16 spell_id, [string name = nullptr], [uint32 duration = 0], [Mob* target = nullptr], [bool sticktarg = 0])"); // @categories Pet
	{
		Mob *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		char *name;
		uint32 duration;
		Mob *target;
		bool sticktarg;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			name = nullptr;
		else
			name = (char *) SvPV_nolen(ST(2));

		if (items < 4)
			duration = 0;
		else
			duration = (uint32) SvUV(ST(3));

		if (items < 5)
			target = nullptr;
		else if (sv_derived_from(ST(4), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(4)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "owner is not of type Mob");

		if (items < 6)
			sticktarg = false;
		else {
			sticktarg = (bool) SvTRUE(ST(5));
		}

		THIS->TemporaryPets(spell_id, target, name, duration, true, sticktarg);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_TypesTempPet); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_TypesTempPet) {
	dXSARGS;
	if (items < 2 || items > 7)
		Perl_croak(aTHX_ "Usage: Mob::TypesTempPet(THIS, uint32 type_id, [string name = nullptr], [uint32 duration = 0], [bool follow = 0], [Mob* target = nullptr], [bool stick_targ = 0])"); // @categories Pet
	{
		Mob *THIS;
		uint32 typesid = (uint32) SvUV(ST(1));
		char *name;
		uint32 duration;
		bool   follow;
		Mob *target;
		bool sticktarg;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			name = nullptr;
		else
			name = (char *) SvPV_nolen(ST(2));

		if (items < 4)
			duration = 0;
		else
			duration = (uint32) SvUV(ST(3));

		if (items < 5)
			follow = true;
		else {
			follow = (bool) SvTRUE(ST(4));
		}

		if (items < 6)
			target = nullptr;
		else if (sv_derived_from(ST(5), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(5)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");


		if (items < 7)
			sticktarg = false;
		else {
			sticktarg = (bool) SvTRUE(ST(6));
		}

		THIS->TypesTemporaryPets(typesid, target, name, duration, follow, sticktarg);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetBaseRace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetBaseRace) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBaseRace(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBaseRace();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBaseGender); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetBaseGender) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBaseGender(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBaseGender();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDeity); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDeity) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDeity(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDeity();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetRace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetRace) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetRace(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetRace();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetGender); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetGender) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetGender(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetGender();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetTexture); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetTexture) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetTexture(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetTexture();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHelmTexture); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHelmTexture) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHelmTexture(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHelmTexture();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHairColor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHairColor) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHairColor(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHairColor();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBeardColor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetBeardColor) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBeardColor(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBeardColor();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetEyeColor1); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetEyeColor1) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetEyeColor1(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetEyeColor1();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetEyeColor2); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetEyeColor2) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetEyeColor2(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetEyeColor2();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHairStyle); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHairStyle) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHairStyle(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHairStyle();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetLuclinFace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetLuclinFace) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetLuclinFace(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetLuclinFace();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBeard); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetBeard) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBeard(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBeard();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDrakkinHeritage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDrakkinHeritage) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDrakkinHeritage(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDrakkinHeritage();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDrakkinTattoo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDrakkinTattoo) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDrakkinTattoo(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDrakkinTattoo();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDrakkinDetails); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDrakkinDetails) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDrakkinDetails(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDrakkinDetails();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetClass); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetClass) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetClass(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetClass();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetLevel) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetLevel(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetLevel();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetCleanName); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetCleanName) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetCleanName(THIS)"); // @categories Script Utility
	{
		Mob        *THIS;
		Const_char *RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCleanName();
		sv_setpv(TARG, RETVAL);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_GetTarget); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetTarget) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetTarget(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetTarget();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetTarget); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetTarget) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetTarget(THIS, mob)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *mob;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			mob = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "mob is not of type Mob");
		if (mob == nullptr)
			Perl_croak(aTHX_ "mob is nullptr, avoiding crash.");

		THIS->SetTarget(mob);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetHPRatio); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHPRatio) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHPRatio(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHPRatio();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsWarriorClass); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsWarriorClass) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsWarriorClass(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsWarriorClass();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHP) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHP(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHP();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxHP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxHP) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxHP(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxHP();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetItemHPBonuses); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetItemHPBonuses) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetItemHPBonuses(THIS)"); // @categories Inventory and Items, Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetItemHPBonuses();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSpellHPBonuses); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSpellHPBonuses) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetSpellHPBonuses(THIS)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSpellHPBonuses();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSpellIDFromSlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSpellIDFromSlot) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetSpellIDFromSlot(THIS, slot)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int   RETVAL;
		dXSTARG;
		uint8 slot = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		if (slot > THIS->GetMaxBuffSlots())
			RETVAL = -1;
		else
			RETVAL = THIS->GetSpellIDFromSlot(slot);

		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWalkspeed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWalkspeed) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWalkspeed(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetWalkspeed();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetRunspeed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetRunspeed) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetRunspeed(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetRunspeed();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetCasterLevel); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetCasterLevel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetCasterLevel(THIS, spell_id)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int    RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCasterLevel(spell_id);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxMana); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxMana) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxMana(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxMana();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMana); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMana) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMana(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMana();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetMana); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetMana) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetMana(THIS, amount)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 amount = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetMana(amount);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetManaRatio); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetManaRatio) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetManaRatio(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetManaRatio();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetAC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetAC(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAC();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDisplayAC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDisplayAC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDisplayAC(THIS)");
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDisplayAC();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetATK); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetATK) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetATK(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetATK();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSTR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSTR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetSTR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSTR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSTA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSTA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetSTA(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSTA();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDEX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDEX) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDEX(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDEX();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetAGI); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAGI) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetAGI(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAGI();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetINT); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetINT) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetINT(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetINT();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWIS); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWIS) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWIS(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetWIS();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetCHA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetCHA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetCHA(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCHA();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetFR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetFR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetFR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetFR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetDR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetDR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetPR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetPR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetPR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetPR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetCR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetCR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetCR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetCorruption); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetCorruption) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetCorruption(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCorrup();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetPhR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetPhR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetPhR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetPhR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxSTR); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxSTR) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxSTR(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxSTR();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxSTA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxSTA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxSTA(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxSTA();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxDEX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxDEX) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxDEX(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxDEX();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxAGI); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxAGI) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxAGI(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxAGI();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxINT); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxINT) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxINT(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxINT();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxWIS); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxWIS) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxWIS(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxWIS();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMaxCHA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetMaxCHA) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMaxCHA(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMaxCHA();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetActSpellRange); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetActSpellRange) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetActSpellRange(THIS, uint16 spell_id, float range)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		float  RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		float  range    = (float) SvNV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetActSpellRange(spell_id, range);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetActSpellDamage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetActSpellDamage) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetActSpellDamage(THIS, uint16 spell_id, int32 value)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32  RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int32  value    = (int32) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetActSpellDamage(spell_id, value);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetActSpellHealing); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetActSpellHealing) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetActSpellHealing(THIS, uint16 spell_id, int32 value)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32  RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int32  value    = (int32) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetActSpellHealing(spell_id, value);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetActSpellCost); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetActSpellCost) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetActSpellCost(THIS, uint16 spell_id, int32 cost)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32  RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int32  cost     = (int32) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetActSpellCost(spell_id, cost);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetActSpellDuration); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetActSpellDuration) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetActSpellDuration(THIS, uint16 spell_id, int32 duration)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32  RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int32  duration = (int32) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetActSpellDuration(spell_id, duration);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetActSpellCasttime); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetActSpellCasttime) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetActSpellCasttime(THIS, uint16 spell_id, uint32 cast_time)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32  RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		int32  casttime = (int32) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetActSpellCasttime(spell_id, casttime);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_ResistSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ResistSpell) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Mob::ResistSpell(THIS, uint8 resist_type, uint16 spell_id, [Mob* caster = nullptr])"); // @categories Spells and Disciplines, Script Utility
	{
		Mob *THIS;
		double RETVAL;
		dXSTARG;
		uint8  ressit_type = (uint8) SvUV(ST(1));
		uint16 spell_id    = (uint16) SvUV(ST(2));
		Mob *caster;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(3), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(3)));
			caster = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "caster is not of type Mob");
		if (caster == nullptr)
			Perl_croak(aTHX_ "caster is nullptr, avoiding crash.");

		RETVAL = THIS->ResistSpell(ressit_type, spell_id, caster);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSpecializeSkillValue); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSpecializeSkillValue) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetSpecializeSkillValue(THIS, uint16 spell_id)"); // @categories Skills and Recipes, Spells and Disciplines
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSpecializeSkillValue(spell_id);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetNPCTypeID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetNPCTypeID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetNPCTypeID(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetNPCTypeID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsTargeted); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsTargeted) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsTargeted(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsTargeted();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetX) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetX(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetX();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetY) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetY(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetY();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetZ); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetZ) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetZ(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetZ();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHeading); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHeading) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHeading(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHeading();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}


XS(XS_Mob_GetWaypointX); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWaypointX) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWaypointX(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCurrentWayPoint().x;
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWaypointY); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWaypointY) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWaypointY(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCurrentWayPoint().y;
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWaypointZ); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWaypointZ) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWaypointZ(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCurrentWayPoint().z;
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWaypointH); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWaypointH) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWaypointH(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCurrentWayPoint().w;
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWaypointPause); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWaypointPause) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWaypointPause(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCWPP();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetWaypointID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetWaypointID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetWaypointID(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetCWP();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetCurrentWP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetCurrentWP) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetCurrentWP(THIS, waypoint)"); // @categories Script Utility
	{
		Mob *THIS;
		uint16 waypoint = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetCurrentWP(waypoint);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetSize); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSize) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetSize(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSize();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetFollowID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetFollowID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetFollowID(THIS, id)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetFollowID(id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetFollowID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetFollowID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetFollowID(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetFollowID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_Message); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Message) {
	dXSARGS;
	if (items < 3)
		Perl_croak(aTHX_ "Usage: Mob::Message(THIS, uint32 emote_color_type, string message)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 type = (uint32) SvUV(ST(1));
		char *message = (char *) SvPV_nolen(ST(2));
		VALIDATE_THIS_IS_MOB;

		if (RuleB(Chat, QuestDialogueUsesDialogueWindow) && THIS->IsClient()) {
			std::string window_markdown = message;
			DialogueWindow::Render(THIS->CastToClient(), window_markdown);
		}
		else if (RuleB(Chat, AutoInjectSaylinksToClientMessage)) {
			std::string new_message = EQ::SayLinkEngine::InjectSaylinksIfNotExist(message);
			THIS->Message(type, new_message.c_str());
		}
		else {
			THIS->Message(type, message);
		}
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Message_StringID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Message_StringID) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::Message_StringID(THIS, uint32 emote_color_type, uint32 string_id, [uint32 distance = 0])"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 type      = (uint32) SvUV(ST(1));
		uint32 string_id = (uint32) SvUV(ST(2));
		uint32 distance;
		VALIDATE_THIS_IS_MOB;
		if (items < 4)
			distance = 0;
		else {
			distance = (uint32) SvUV(ST(3));
		}

		THIS->MessageString(type, string_id, distance);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Say); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Say) {
	dXSARGS;
	if (items < 2)
		Perl_croak(aTHX_ "Usage: Mob::Say(THIS, string message)"); // @categories Script Utility
	{
		Mob  *THIS;
		char *format = (char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->Say(format);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Shout); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Shout) {
	dXSARGS;
	if (items < 2)
		Perl_croak(aTHX_ "Usage: Mob::Shout(THIS, string message)"); // @categories Script Utility
	{
		Mob  *THIS;
		char *format = (char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->Shout(format);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Emote); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Emote) {
	dXSARGS;
	if (items < 2)
		Perl_croak(aTHX_ "Usage: Mob::Emote(THIS, string message)"); // @categories Script Utility
	{
		Mob  *THIS;
		char *format = (char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->Emote(format);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_InterruptSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_InterruptSpell) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Mob::InterruptSpell(THIS, [uint16 spell_id = 0xFFFF])"); // @categories Script Utility
	{
		Mob *THIS;
		uint16 spellid;
		VALIDATE_THIS_IS_MOB;
		if (items < 2)
			spellid = 0xFFFF;
		else {
			spellid = (uint16) SvUV(ST(1));
		}

		THIS->InterruptSpell(spellid);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CastSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastSpell) {
	dXSARGS;
	if (items < 3 || items > 7)
		Perl_croak(aTHX_ "Usage: Mob::CastSpell(THIS, uint16 spell_id, uint16 target_id, [int slot = 22], [int32 cast_time = -1], [int32 mana_cost = -1], [int16 resist_adjust = 0])"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		uint16             spell_id  = (uint16) SvUV(ST(1));
		uint16             target_id = (uint16) SvUV(ST(2));
		EQ::spells::CastingSlot slot;
		int32              casttime;
		int32              mana_cost;
		int16              resist_adjust;
		VALIDATE_THIS_IS_MOB;
		if (items < 4)
			slot = EQ::spells::CastingSlot::Item;
		else {
			slot = static_cast<EQ::spells::CastingSlot>(SvUV(ST(3)));
		}

		if (items < 5)
			casttime = -1;
		else {
			casttime = (int32) SvIV(ST(4));
		}

		if (items < 6)
			mana_cost = -1;
		else {
			mana_cost = (int32) SvIV(ST(5));
		}

		if (items < 7) {
			resist_adjust = 0;
		} else {
			resist_adjust = (int16) SvIV(ST(6));
		}

		if (resist_adjust ==
		    0)//If you do not pass resist adjust as nullptr it will ignore the spells default resist adjust
			THIS->CastSpell(spell_id, target_id, slot, casttime, mana_cost, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0);
		else
			THIS->CastSpell(spell_id, target_id, slot, casttime, mana_cost, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0,
			                &resist_adjust);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SpellFinished); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SpellFinished) {
	dXSARGS;
	if (items < 2 || items > 5)
		Perl_croak(aTHX_ "Usage: Mob::SpellFinished(uint16 spell_id, [Mob* spell_target = this], [uint16 mana_cost = 0], [uint16 resist_diff = 0])"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		Mob *spell_target;
		uint16 mana_cost = 0;
		int16  resist_diff;
		VALIDATE_THIS_IS_MOB;
		spell_target = THIS;

		if (items > 2) {
			if (sv_derived_from(ST(2), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(2)));
				spell_target = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "spell_target is not of type Mob");
			if (spell_target == nullptr)
				Perl_croak(aTHX_ "spell_target is nullptr, avoiding crash.");

		}

		if (items > 3)
			mana_cost = (uint16) SvUV(ST(3));

		if (items > 4) {
			resist_diff = (int16) SvUV(ST(4));
		} else {
			resist_diff = spells[spell_id].resist_difficulty;
		}

		THIS->SpellFinished(spell_id, spell_target, EQ::spells::CastingSlot::Item, mana_cost, -1, resist_diff);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_IsImmuneToSpell); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsImmuneToSpell) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::IsImmuneToSpell(THIS, uint16 spell_id, [Mob* caster = nullptr])"); // @categories Spells and Disciplines, Script Utility
	{
		Mob *THIS;
		bool   RETVAL;
		uint16 spell_id = (uint16) SvUV(ST(1));
		Mob *caster;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(2), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(2)));
			caster = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "caster is not of type Mob");
		if (caster == nullptr)
			Perl_croak(aTHX_ "caster is nullptr, avoiding crash.");

		RETVAL = THIS->IsImmuneToSpell(spell_id, caster);
		ST(0)           = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_BuffFadeBySpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_BuffFadeBySpellID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::BuffFadeBySpellID(THIS, uint16 spell_id)"); // @categories Script Utility, Spells and Disciplines
	{
		Mob *THIS;
		uint16 spell_id = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->BuffFadeBySpellID(spell_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_BuffFadeByEffect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_BuffFadeByEffect) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::BuffFadeByEffect(THIS, int effect_id, int skip_slot = -1)"); // @categories Script Utility, Spells and Disciplines
	{
		Mob *THIS;
		int effect_id = (int) SvIV(ST(1));
		int skipslot;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			skipslot = -1;
		else {
			skipslot = (int) SvIV(ST(2));
		}

		THIS->BuffFadeByEffect(effect_id, skipslot);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_BuffFadeAll); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_BuffFadeAll) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::BuffFadeAll(THIS)"); // @categories Script Utility, Spells and Disciplines
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->BuffFadeAll();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_BuffFadeBySlot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_BuffFadeBySlot) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::BuffFadeBySlot(THIS, int slot, bool recalc_bonuses = true)"); // @categories Script Utility, Spells and Disciplines
	{
		Mob *THIS;
		int  slot = (int) SvIV(ST(1));
		bool iRecalcBonuses;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			iRecalcBonuses = true;
		else {
			iRecalcBonuses = (bool) SvTRUE(ST(2));
		}

		THIS->BuffFadeBySlot(slot, iRecalcBonuses);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CanBuffStack); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanBuffStack) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::CanBuffStack(THIS, uint16 spell_id, uint8 caster_level, [bool fail_if_overwritten = false])"); // @categories Script Utility, Spells and Disciplines
	{
		Mob *THIS;
		int    RETVAL;
		dXSTARG;
		uint16 spellid      = (uint16) SvUV(ST(1));
		uint8  caster_level = (uint8) SvUV(ST(2));
		bool   iFailIfOverwrite;
		VALIDATE_THIS_IS_MOB;
		if (items < 4)
			iFailIfOverwrite = false;
		else {
			iFailIfOverwrite = (bool) SvTRUE(ST(3));
		}

		RETVAL = THIS->CanBuffStack(spellid, caster_level, iFailIfOverwrite);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsCasting); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsCasting) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsCasting(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsCasting();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CastingSpellID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastingSpellID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CastingSpellID(THIS)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CastingSpellID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetAppearance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetAppearance) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::SetAppearance(THIS, int appearance [0|1|2|3|4], [ignore_self = true])"); // @categories Stats and Attributes
	{
		Mob *THIS;
		EmuAppearance app = (EmuAppearance) SvUV(ST(1));
		bool          iIgnoreSelf;
		VALIDATE_THIS_IS_MOB;
		if (items < 3)
			iIgnoreSelf = true;
		else {
			iIgnoreSelf = (bool) SvTRUE(ST(2));
		}

		THIS->SetAppearance(app, iIgnoreSelf);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetAppearance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAppearance) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetAppearance(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		EmuAppearance RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAppearance();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetRunAnimSpeed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetRunAnimSpeed) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetRunAnimSpeed(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetRunAnimSpeed();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetRunAnimSpeed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetRunAnimSpeed) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetRunAnimSpeed(THIS, int8 speed)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int8 in = (int8) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetRunAnimSpeed(in);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetPetID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetPetID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetPetID(THIS, uint16 new_pet_id)"); // @categories Pet
	{
		Mob *THIS;
		uint16 NewPetID = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetPetID(NewPetID);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetPetID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetPetID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetPetID(THIS)"); // @categories Script Utility, Pet
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetPetID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetOwnerID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetOwnerID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetOwnerID(THIS, uint16 new_owner_id)"); // @categories Pet
	{
		Mob *THIS;
		uint16 NewOwnerID = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetOwnerID(NewOwnerID);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetOwnerID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetOwnerID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetOwnerID(THIS)"); // @categories Script Utility, Pet
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetOwnerID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetPetType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetPetType) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetPetType(THIS)"); // @categories Script Utility, Pet
	{
		Mob *THIS;
		uint16 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetPetType();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBodyType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetBodyType) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBodyType(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBodyType();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_Stun); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Stun) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::Stun(THIS, int duration)");
	{
		Mob *THIS;
		int duration = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->Stun(duration);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Spin); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Spin) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::Spin(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->Spin();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_Kill); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Kill) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::Kill(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->Kill();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetInvul); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetInvul) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetInvul(THIS, bool set_invulnerable)"); // @categories Script Utility
	{
		Mob *THIS;
		bool invul = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetInvul(invul);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetInvul); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetInvul) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetInvul(THIS)"); // @categories Script Utility, Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetInvul();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SetExtraHaste); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetExtraHaste) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetExtraHaste(THIS, int haste)"); // @categories Script Utility, Stats and Attributes
	{
		Mob *THIS;
		int Haste = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetExtraHaste(Haste);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetHaste); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHaste) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHaste(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHaste();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHandToHandDamage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHandToHandDamage) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHandToHandDamage(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHandToHandDamage();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_CanThisClassDoubleAttack); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanThisClassDoubleAttack) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CanThisClassDoubleAttack(THIS)"); // @categories Skills and Recipes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanThisClassDoubleAttack();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CanThisClassDualWield); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanThisClassDualWield) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CanThisClassDualWield(THIS)"); // @categories Skills and Recipes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanThisClassDualWield();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CanThisClassRiposte); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanThisClassRiposte) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CanThisClassRiposte(THIS)"); // @categories Skills and Recipes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanThisClassRiposte();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CanThisClassDodge); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanThisClassDodge) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CanThisClassDodge(THIS)"); // @categories Skills and Recipes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanThisClassDodge();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CanThisClassParry); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanThisClassParry) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CanThisClassParry(THIS)"); // @categories Skills and Recipes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanThisClassParry();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHandToHandDelay); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHandToHandDelay) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHandToHandDelay(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHandToHandDelay();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetClassLevelFactor); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetClassLevelFactor) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetClassLevelFactor(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetClassLevelFactor();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_Mesmerize); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Mesmerize) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::Mesmerize(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->Mesmerize();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_IsMezzed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsMezzed) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsMezzed(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsMezzed();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsStunned); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsStunned) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsStunned(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsStunned();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}


XS(XS_Mob_StartEnrage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_StartEnrage) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::StartEnrage(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->StartEnrage();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_IsEnraged); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsEnraged) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsEnraged(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsEnraged();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetReverseFactionCon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetReverseFactionCon) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetReverseFactionCon(THIS, iOther)"); // @categories Faction
	{
		Mob *THIS;
		FACTION_VALUE RETVAL;
		dXSTARG;
		Mob *iOther;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			iOther = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "iOther is not of type Mob");
		if (iOther == nullptr)
			Perl_croak(aTHX_ "iOther is nullptr, avoiding crash.");

		RETVAL = THIS->GetReverseFactionCon(iOther);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsAIControlled); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsAIControlled) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsAIControlled(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsAIControlled();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetAggroRange); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAggroRange) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetAggroRange(THIS)"); // @categories Stats and Attributes, Hate and Aggro
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAggroRange();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetAssistRange); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAssistRange) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetAssistRange(THIS)"); // @categories Stats and Attributes, Hate and Aggro
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAssistRange();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetPetOrder); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetPetOrder) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetPetOrder(THIS, i)"); // @categories Pet
	{
		Mob *THIS;
		Mob::eStandingPetOrder i = (Mob::eStandingPetOrder) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetPetOrder(i);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetPetOrder); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetPetOrder) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetPetOrder(THIS)"); // @categories Script Utility, Pet
	{
		Mob *THIS;
		Mob::eStandingPetOrder RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetPetOrder();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsRoamer); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsRoamer) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsRoamer(THIS)"); // @categories Script Utility, Spawns
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsRoamer();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsRooted); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsRooted) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsRooted(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsRooted();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_AddToHateList); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_AddToHateList) {
	dXSARGS;
	if (items < 2 || items > 7)
		Perl_croak(aTHX_ "Usage: Mob::AddToHateList(THIS, Mob* other, [int32 hate = 0], [int32 damage = 0], [bool yell_for_help = true], [bool frenzy = false], [bool buff_tic = false])"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *other;
		int32 hate;
		int32 damage;
		bool  iYellForHelp;
		bool  bFrenzy;
		bool  iBuffTic;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		if (items < 3)
			hate = 0;
		else {
			hate = (int32) SvIV(ST(2));
		}

		if (items < 4)
			damage = 0;
		else {
			damage = (int32) SvIV(ST(3));
		}

		if (items < 5)
			iYellForHelp = true;
		else {
			iYellForHelp = (bool) SvTRUE(ST(4));
		}

		if (items < 6)
			bFrenzy = false;
		else {
			bFrenzy = (bool) SvTRUE(ST(5));
		}

		if (items < 7)
			iBuffTic = false;
		else {
			iBuffTic = (bool) SvTRUE(ST(6));
		}

		THIS->AddToHateList(other, hate, damage, iYellForHelp, bFrenzy, iBuffTic);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetHate); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetHate) {
	dXSARGS;
	if (items < 2 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::SetHate(THIS, Mob* other, [int32 hate = 0], [int32 damage = 0])"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *other;
		int32 hate;
		int32 damage;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		if (items < 3)
			hate = 0;
		else {
			hate = (int32) SvIV(ST(2));
		}

		if (items < 4)
			damage = 0;
		else {
			damage = (int32) SvIV(ST(3));
		}

		THIS->SetHateAmountOnEnt(other, hate, damage);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_HalveAggro);
XS(XS_Mob_HalveAggro) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::HalveAggro(THIS, Mob* other)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		THIS->HalveAggro(other);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DoubleAggro);
XS(XS_Mob_DoubleAggro) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::DoubleAggro(THIS, Mob* other)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		THIS->DoubleAggro(other);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetHateAmount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateAmount) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::GetHateAmount(THIS, Mob* mob, [bool is_damage = false])"); // @categories Hate and Aggro
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		Mob *tmob;
		bool is_dam;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			tmob = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "tmob is not of type Mob");
		if (tmob == nullptr)
			Perl_croak(aTHX_ "tmob is nullptr, avoiding crash.");

		if (items < 3)
			is_dam = false;
		else {
			is_dam = (bool) SvTRUE(ST(2));
		}

		RETVAL = THIS->GetHateAmount(tmob, is_dam);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetDamageAmount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetDamageAmount) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetDamageAmount(THIS, Mob* target_mob)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		Mob *tmob;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			tmob = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "tmob is not of type Mob");
		if (tmob == nullptr)
			Perl_croak(aTHX_ "tmob is nullptr, avoiding crash.");

		RETVAL = THIS->GetDamageAmount(tmob);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHateTop); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateTop) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateTop(THIS)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHateTop();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHateDamageTop); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateDamageTop) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetHateDamageTop(THIS, Mob* other)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *RETVAL;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		RETVAL = THIS->GetHateDamageTop(other);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHateRandom); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateRandom) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateRandom(THIS)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHateRandom();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsEngaged); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsEngaged) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsEngaged(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsEngaged();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_HateSummon); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_HateSummon) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HateSummon(THIS)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HateSummon();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_FaceTarget); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_FaceTarget) {
	dXSARGS;
	if (items < 1 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::FaceTarget(THIS, [Mob* target = 0])"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *MobToFace;
		VALIDATE_THIS_IS_MOB;
		if (items < 2)
			MobToFace = 0;
		else {
			if (sv_derived_from(ST(1), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(1)));
				MobToFace = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "MobToFace is not of type Mob");
			if (MobToFace == nullptr)
				Perl_croak(aTHX_ "MobToFace is nullptr, avoiding crash.");
		}

		THIS->FaceTarget(MobToFace);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetHeading); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetHeading) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetHeading(THIS, float heading)"); // @categories Script Utility
	{
		Mob *THIS;
		float iHeading = (float) SvNV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetHeading(iHeading);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_WipeHateList); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_WipeHateList) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::WipeHateList(THIS)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->WipeHateList();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CheckAggro); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CheckAggro) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::CheckAggro(THIS, Mob* other)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		bool RETVAL;
		Mob *other;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			other = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "other is not of type Mob");
		if (other == nullptr)
			Perl_croak(aTHX_ "other is nullptr, avoiding crash.");

		RETVAL = THIS->CheckAggro(other);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CalculateHeadingToTarget); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CalculateHeadingToTarget) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::CalculateHeadingToTarget(THIS, float x, float y)"); // @categories Script Utility
	{
		Mob *THIS;
		int8  RETVAL;
		dXSTARG;
		float in_x = (float) SvNV(ST(1));
		float in_y = (float) SvNV(ST(2));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CalculateHeadingToTarget(in_x, in_y);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_RunTo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RunTo) {
	dXSARGS;
	if (items < 4 || items > 5)
		Perl_croak(aTHX_
			"Usage: Mob::RunTo(THIS, float x, float y, float z)");
	{
		Mob *THIS;
		float x = (float)SvNV(ST(1));
		float y = (float)SvNV(ST(2));
		float z = (float)SvNV(ST(3));
		VALIDATE_THIS_IS_MOB;
		THIS->RunTo(x, y, z);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_WalkTo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_WalkTo) {
	dXSARGS;
	if (items < 4 || items > 5)
		Perl_croak(aTHX_
			"Usage: Mob::WalkTo(THIS, float x, float y, float z)");
	{
		Mob *THIS;
		float x = (float)SvNV(ST(1));
		float y = (float)SvNV(ST(2));
		float z = (float)SvNV(ST(3));
		VALIDATE_THIS_IS_MOB;
		THIS->WalkTo(x, y, z);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_NavigateTo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_NavigateTo) {
	dXSARGS;
	if (items < 4 || items > 5)
		Perl_croak(aTHX_ "Usage: Mob::NavigateTo(THIS, float x, float y, float z)"); // @categories Script Utility
	{
		Mob *THIS;
		float x     = (float) SvNV(ST(1));
		float y     = (float) SvNV(ST(2));
		float z     = (float) SvNV(ST(3));
		VALIDATE_THIS_IS_MOB;
		THIS->NavigateTo(x, y, z);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_StopNavigation); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_StopNavigation) {
	dXSARGS;
	if (items < 5 || items > 6)
		Perl_croak(aTHX_
			"Usage: Mob::StopNavigation(THIS)");
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->StopNavigation();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CalculateDistance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CalculateDistance) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Mob::CalculateDistance(THIS, float x, float y, float z)"); // @categories Script Utility
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		float x = (float) SvNV(ST(1));
		float y = (float) SvNV(ST(2));
		float z = (float) SvNV(ST(3));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CalculateDistance(x, y, z);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SendTo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SendTo) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Mob::SendTo(THIS, float new_x, float new_y, float new_z)"); // @categories Script Utility
	{
		Mob *THIS;
		float new_x = (float) SvNV(ST(1));
		float new_y = (float) SvNV(ST(2));
		float new_z = (float) SvNV(ST(3));
		VALIDATE_THIS_IS_MOB;
		THIS->SendTo(new_x, new_y, new_z);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SendToFixZ); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SendToFixZ) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Mob::SendToFixZ(THIS, float new_x, float new_y, float new_z)"); // @categories Script Utility
	{
		Mob *THIS;
		float new_x = (float) SvNV(ST(1));
		float new_y = (float) SvNV(ST(2));
		float new_z = (float) SvNV(ST(3));
		VALIDATE_THIS_IS_MOB;
		THIS->SendToFixZ(new_x, new_y, new_z);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_NPCSpecialAttacks); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_NPCSpecialAttacks) {
	dXSARGS;
	if (items < 3 || items > 5)
		Perl_croak(aTHX_ "Usage: Mob::NPCSpecialAttacks(THIS, string abilities_string, int perm_tag, [bool reset = true], [bool remove = true])"); // @categories Stats and Attributes
	{
		Mob  *THIS;
		char *parse = (char *) SvPV_nolen(ST(1));
		int  permtag = (int) SvIV(ST(2));
		bool reset   = items == 4 ? (bool) SvTRUE(ST(3)) : true;
		bool remove  = items == 5 ? (bool) SvTRUE(ST(4)) : false;
		VALIDATE_THIS_IS_MOB;
		THIS->NPCSpecialAttacks(parse, permtag, reset, remove);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DontHealMeBefore); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DontHealMeBefore) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::DontHealMeBefore(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->DontHealMeBefore();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_DontBuffMeBefore); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DontBuffMeBefore) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::DontBuffMeBefore(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->DontBuffMeBefore();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_DontDotMeBefore); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DontDotMeBefore) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::DontDotMeBefore(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->DontDotMeBefore();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_DontRootMeBefore); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DontRootMeBefore) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::DontRootMeBefore(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->DontRootMeBefore();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_DontSnareMeBefore); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DontSnareMeBefore) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::DontSnareMeBefore(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->DontSnareMeBefore();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetResist); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetResist) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetResist(THIS, type)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int16 RETVAL;
		dXSTARG;
		uint8 type = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetResist(type);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_Charmed); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_Charmed) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::Charmed(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->Charmed();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetLevelHP); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetLevelHP) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetLevelHP(THIS, uint8 level)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint8  tlevel = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetLevelHP(tlevel);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetZoneID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetZoneID) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetZoneID(THIS)"); // @categories Zones
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetZoneID();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_CheckAggroAmount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CheckAggroAmount) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::CheckAggroAmount(THIS, uint16 spell_id)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint16 spellid = (uint16) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CheckAggroAmount(spellid, nullptr);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_CheckHealAggroAmount); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CheckHealAggroAmount) {
	dXSARGS;
	if (items != 2 && items != 3)
		Perl_croak(aTHX_ "Usage: Mob::CheckHealAggroAmount(THIS, uint16 spell_id, uint32 possible_heal_amt)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint16 spellid  = (uint16) SvUV(ST(1));
		uint32 possible = 0;
		VALIDATE_THIS_IS_MOB;
		if (items == 3) {
			possible = (uint32) SvUV(ST(2));
		}

		RETVAL = THIS->CheckHealAggroAmount(spellid, nullptr, possible);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetAA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAA) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetAA(THIS, uint32 rank_id)"); // @categories Alternative Advancement
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint32 rank_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAA(rank_id);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetAAByAAID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAAByAAID) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetAAByAAID(THIS, uint32 aa_id)"); // @categories Alternative Advancement
	{
		Mob *THIS;
		uint32 RETVAL;
		dXSTARG;
		uint32 aa_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAAByAAID(aa_id);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetAA); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetAA) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::SetAA(THIS, int aa_id, int points, [int charges = 0])"); // @categories Alternative Advancement, Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		int  aa_id   = (int) SvIV(ST(1));
		int  points  = (int) SvIV(ST(2));
		int  charges = (items == 4) ? (int) SvIV(ST(3)) : 0;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->SetAA(aa_id, points, charges);
		ST(0)        = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_DivineAura); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DivineAura) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::DivineAura(THIS)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->DivineAura();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_AddFeignMemory); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_AddFeignMemory) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::AddFeignMemory(THIS, Client* attacker)"); // @categories Script Utility
	{
		Mob    *THIS;
		Client *attacker;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Client")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			attacker = INT2PTR(Client *, tmp);
		} else
			Perl_croak(aTHX_ "attacker is not of type Client");
		if (attacker == nullptr)
			Perl_croak(aTHX_ "attacker is nullptr, avoiding crash.");

		THIS->AddFeignMemory(attacker);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_RemoveFromFeignMemory); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RemoveFromFeignMemory) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::RemoveFromFeignMemory(THIS, Client* attacker)"); // @categories Script Utility, Hate and Aggro
	{
		Mob    *THIS;
		Client *attacker;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Client")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			attacker = INT2PTR(Client *, tmp);
		} else
			Perl_croak(aTHX_ "attacker is not of type Client");
		if (attacker == nullptr)
			Perl_croak(aTHX_ "attacker is nullptr, avoiding crash.");

		THIS->RemoveFromFeignMemory(attacker);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ClearFeignMemory); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ClearFeignMemory) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::ClearFeignMemory(THIS)"); // @categories Script Utility, Hate and Aggro
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->ClearFeignMemory();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetOOCRegen); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetOOCRegen) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetOOCRegen(THIS, int32 new_ooc_regen)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 newoocregen = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetOOCRegen(newoocregen);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetEntityVariable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetEntityVariable) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetEntityVariable(THIS, string id)"); // @categories Script Utility
	{
		Mob        *THIS;
		Const_char *id = SvPV_nolen(ST(1));
		Const_char *RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetEntityVariable(id);
		sv_setpv(TARG, RETVAL);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_EntityVariableExists); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_EntityVariableExists) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::EntityVariableExists(THIS, string id)");
	{
		Mob        *THIS;
		Const_char *id = SvPV_nolen(ST(1));
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->EntityVariableExists(id);
		ST(0)          = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SetEntityVariable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetEntityVariable) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::SetEntityVariable(THIS, string id, string var)"); // @categories Script Utility
	{
		Mob        *THIS;
		Const_char *id  = SvPV_nolen(ST(1));
		const char *var = (const char *) SvPV_nolen(ST(2));
		VALIDATE_THIS_IS_MOB;
		THIS->SetEntityVariable(id, var);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetHateList); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateList) {
	dXSARGS;
	int num_entries = 0;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateList(THIS)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		auto hate_list = THIS->GetHateList();
		auto iter      = hate_list.begin();

		while (iter != hate_list.end()) {
			struct_HateList *entry = (*iter);
			ST(0) = sv_newmortal();
			sv_setref_pv(ST(0), "HateEntry", (void *) entry);
			XPUSHs(ST(0));
			num_entries++;
			iter++;
		}
	}
	XSRETURN(num_entries);
}

XS(XS_Mob_SignalClient); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SignalClient) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::SignalClient(THIS, Client* client, uint32 data)"); // @categories Script Utility
	{
		Mob    *THIS;
		Client *client = nullptr;
		uint32 data = (uint32) SvUV(ST(2));
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Client")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			client = INT2PTR(Client *, tmp);
		} else
			Perl_croak(aTHX_ "client is not of type Client");
		if (client == nullptr)
			Perl_croak(aTHX_ "client is nullptr, avoiding crash.");

		client->Signal(data);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CombatRange); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CombatRange) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::CombatRange(THIS, Mob* target)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *target = nullptr;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");
		if (target == nullptr)
			Perl_croak(aTHX_ "target is nullptr, avoiding crash.");

		RETVAL = THIS->CombatRange(target);
		ST(0)       = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_DoSpecialAttackDamage); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DoSpecialAttackDamage) {
	dXSARGS;
	if (items < 4 || items > 6)
		Perl_croak(aTHX_ "Usage: Mob::DoSpecialAttackDamage(THIS, Mob* target, int skill, int32 max_damage, [int32 min_damage = 1], [int32 hate_override = -11])"); // @categories Script Utility, Skills and Attributes
	{
		Mob *THIS;
		Mob *target;
		EQ::skills::SkillType attack_skill  = (EQ::skills::SkillType) SvUV(ST(2));
		int32                    max_damage    = (int32) SvIV(ST(3));
		int32                    min_damage    = 1;
		int32                    hate_override = -11;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");
		if (target == nullptr)
			Perl_croak(aTHX_ "target is nullptr, avoiding crash.");

		if (items > 4) {
			min_damage = (int32) SvIV(ST(4));
		}

		if (items == 6) {
			hate_override = (int32) SvIV(ST(5));
		}

		THIS->DoSpecialAttackDamage(target, attack_skill, max_damage, min_damage, hate_override);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CheckLoS); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CheckLoS) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::CheckLoS(THIS, Mob*)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *mob;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			mob = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "mob is not of type Mob");
		if (mob == nullptr)
			Perl_croak(aTHX_ "mob is nullptr, avoiding crash.");

		RETVAL = THIS->CheckLosFN(mob);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_CheckLoSToLoc); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CheckLoSToLoc) {
	dXSARGS;
	if (items != 4 && items != 5)
		Perl_croak(aTHX_ "Usage: Mob::CheckLoSToLoc(THIS, float x, float y, float z, float mob_size)"); // @categories Script Utility
	{
		Mob *THIS;
		float loc_x = (float) SvNV(ST(1));
		float loc_y = (float) SvNV(ST(2));
		float loc_z = (float) SvNV(ST(3));
		float mob_size;
		bool  RETVAL;

		if (items == 5) {
			mob_size = (float) SvNV(ST(4));
		} else {
			mob_size = 6;
		}
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CheckLosFN(loc_x, loc_y, loc_z, mob_size);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_FindGroundZ); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_FindGroundZ) {
	dXSARGS;
	if (items != 3 && items != 4)
		Perl_croak(aTHX_ "Usage: Mob::FindGroundZ(THIS, float x, float y, float z_offset)"); // @categories Script Utility
	{
		Mob *THIS;
		float new_x = (float) SvNV(ST(1));
		float new_y = (float) SvNV(ST(2));
		float z_offset;
		float RETVAL;
		dXSTARG;

		if (items == 4) {
			z_offset = (float) SvNV(ST(3));
		} else {
			z_offset = 10;
		}
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetGroundZ(new_x, new_y, z_offset);
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_ProjectileAnim); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ProjectileAnim) {
	dXSARGS;
	if (items < 3 || items > 9)
		Perl_croak(aTHX_ "Usage: Mob::ProjectileAnim(THIS, Mob* mob, int item_id, [bool is_arrow = false], [float speed = 0], [float angle = 0], [float tilt = 0], [float arc = 0])"); // @categories Script Utility

	{
		Mob *THIS;
		Mob *mob;
		int   item_id = SvUV(ST(2));
		bool  IsArrow = false;
		float speed   = 0;
		float angle   = 0;
		float tilt    = 0;
		float arc     = 0;
		char *IDFile = nullptr;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			mob = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "mob is not of type Mob");
		if (mob == nullptr)
			Perl_croak(aTHX_ "mob is nullptr, avoiding crash.");

		if (items > 3) {
			IsArrow = (bool) SvTRUE(ST(3));
		}
		if (items > 4) {
			speed = (float) SvNV(ST(4));
		}
		if (items > 5) {
			angle = (float) SvNV(ST(5));
		}
		if (items > 6) {
			tilt = (float) SvNV(ST(6));
		}
		if (items > 7) {
			arc = (float) SvNV(ST(7));
		}

		if (items > 8) { IDFile = (char *) SvPV_nolen(ST(8)); }

		THIS->ProjectileAnimation(mob, item_id, IsArrow, speed, angle, tilt, arc, IDFile);

	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_HasNPCSpecialAtk); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_HasNPCSpecialAtk) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::HasNPCSpecialAtk(THIS, string ability_string)"); // @categories Stats and Attributes
	{
		Mob  *THIS;
		char *parse = (char *) SvPV_nolen(ST(1));
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasNPCSpecialAtk(parse);
		ST(0)       = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SendAppearanceEffect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SendAppearanceEffect) {
	dXSARGS;
	if (items < 2 || items > 7)
		Perl_croak(aTHX_ "Usage: Mob::SendAppearanceEffect(THIS, int32 param_1, [int32 param_2 = 0], [int32 param_3 = 0], [int32 param_4 = 0], [int32 param_5 = 0], [Client* single_client_to_send_to = null])"); // @categories Script Utility
	{
		Mob *THIS;
		int32 parm1 = (int32) SvIV(ST(1));
		int32 parm2 = 0;
		int32 parm3 = 0;
		int32 parm4 = 0;
		int32 parm5 = 0;
		Client *client = nullptr;
		VALIDATE_THIS_IS_MOB;
		if (items > 2) { parm2 = (int32) SvIV(ST(2)); }
		if (items > 3) { parm3 = (int32) SvIV(ST(3)); }
		if (items > 4) { parm4 = (int32) SvIV(ST(4)); }
		if (items > 5) { parm5 = (int32) SvIV(ST(5)); }
		if (items > 6) {
			if (sv_derived_from(ST(6), "Client")) {
				IV tmp = SvIV((SV *) SvRV(ST(6)));
				client = INT2PTR(Client *, tmp);
			} else
				Perl_croak(aTHX_ "client is not of type Client");
			if (client == nullptr)
				Perl_croak(aTHX_ "client is nullptr, avoiding crash.");
		}

		THIS->SendAppearanceEffect(parm1, parm2, parm3, parm4, parm5, client);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetFlyMode); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetFlyMode) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetFlyMode(THIS, uint8 flymode[0|1|2|3|4|5])"); // @categories Script Utility
	{
		Mob *THIS;
		GravityBehavior flymode = (GravityBehavior) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetFlyMode(flymode);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetTexture); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetTexture) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetTexture(THIS, int32 texture)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 texture = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SendIllusionPacket(THIS->GetRace(), 0xFF, texture);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetRace); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetRace) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetRace(THIS, int32 race)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 race = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SendIllusionPacket(race);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetGender); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetGender) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetGender(THIS, int32 gender)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 gender = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SendIllusionPacket(THIS->GetRace(), gender);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SendIllusion); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SendIllusion) {
	dXSARGS;
	if (items < 2 || items > 14)
		Perl_croak(aTHX_ "Usage: Mob::SendIllusion(THIS, uint16 race, [uint8 gender = 0xFF], [uint8 texture  face = 0xFF], [uint8 hairstyle = 0xFF], [uint8 hair_color = 0xFF], [uint8 beard = 0xFF], [uint8 beard_color =FF], [uint32 drakkin_tattoo = 0xFFFFFFFF], [uint32 drakkin_details = 0xFFFFFFFF], [float size = -1])"); // @categories Script Utility
	{
		Mob *THIS;
		uint16 race             = (uint16) SvIV(ST(1));
		uint8  gender           = 0xFF;
		uint8  texture          = 0xFF;
		uint8  helmtexture      = 0xFF;
		uint8  face             = 0xFF;
		uint8  hairstyle        = 0xFF;
		uint8  haircolor        = 0xFF;
		uint8  beard            = 0xFF;
		uint8  beardcolor       = 0xFF;
		uint32 drakkin_heritage = 0xFFFFFFFF;
		uint32 drakkin_tattoo   = 0xFFFFFFFF;
		uint32 drakkin_details  = 0xFFFFFFFF;
		float  size             = -1.0f;
		VALIDATE_THIS_IS_MOB;
		if (items > 2) { gender = (uint8) SvIV(ST(2)); }
		if (items > 3) { texture = (uint8) SvIV(ST(3)); }
		if (items > 4) { helmtexture = (uint8) SvIV(ST(4)); }
		if (items > 5) { face = (uint8) SvIV(ST(5)); }
		if (items > 6) { hairstyle = (uint8) SvIV(ST(6)); }
		if (items > 7) { haircolor = (uint8) SvIV(ST(7)); }
		if (items > 8) { beard = (uint8) SvIV(ST(8)); }
		if (items > 9) { beardcolor = (uint8) SvIV(ST(9)); }
		if (items > 10) { drakkin_heritage = (uint32) SvIV(ST(10)); }
		if (items > 11) { drakkin_tattoo = (uint32) SvIV(ST(11)); }
		if (items > 12) { drakkin_details = (uint32) SvIV(ST(12)); }
		if (items > 13) { size = (float) SvNV(ST(13)); }

		THIS->SendIllusionPacket(race, gender, texture, helmtexture, haircolor, beardcolor, 0xFF, 0xFF,
		                         hairstyle, face, beard, 0xFF, drakkin_heritage, drakkin_tattoo, drakkin_details, size);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CameraEffect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CameraEffect) {
	dXSARGS;
	if (items < 2 || items > 5)
		Perl_croak(aTHX_ "Usage: Mob::CameraEffect(THIS, uint32 duration, [uint32 intensity = 0], [Client* single_client = nullptr], [bool is_world_wide = false])"); // @categories Script Utility
	{
		Mob *THIS;
		uint32 duration  = (uint32) SvUV(ST(1));
		uint32 intensity = 0;
		Client *client = nullptr;
		bool global  = false;
		bool nullcli = false;
		VALIDATE_THIS_IS_MOB;
		if (items > 2) { intensity = (uint32) SvUV(ST(2)); }
		if (items > 3) {
			if (sv_derived_from(ST(3), "Client")) {
				IV tmp = SvIV((SV *) SvRV(ST(3)));
				client = INT2PTR(Client *, tmp);
			} else
				nullcli = true;
			if (client == nullptr)
				nullcli = true;
			//Perl_croak(aTHX_ "client is nullptr, avoiding crash.");
		}
		if (items > 4) { global = (bool) SvTRUE(ST(4)); }

		if (nullcli)
			THIS->CameraEffect(duration, intensity, 0, global);
		else
			THIS->CameraEffect(duration, intensity, client, global);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SpellEffect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SpellEffect) {
	dXSARGS;
	if (items < 2 || items > 10)
		Perl_croak(aTHX_ "Usage: Mob::SpellEffect(THIS, uint32 effect, [uint32 duration = 5000], [uint32 finish_delay = 0], [bool zone_wide = false], [uint32 unk20 = 3000], [bool perm_effect = false], [Client* single_client]), [caster_id = 0], [target_id = 0]"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		uint32 effect       = (uint32) SvUV(ST(1));
		uint32 duration     = 5000;
		uint32 finish_delay = 0;
		bool   zone_wide    = true;
		uint32 unk20        = 3000;
		bool   perm_effect  = false;
		Client *client = nullptr;
		uint32 caster_id = 0;
		uint32 target_id = 0;
		bool nullclient = false;
		VALIDATE_THIS_IS_MOB;
		if (items > 2) { duration = (uint32) SvUV(ST(2)); }
		if (items > 3) { finish_delay = (uint32) SvUV(ST(3)); }
		if (items > 4) { zone_wide = (bool) SvTRUE(ST(4)); }
		if (items > 5) { unk20 = (uint32) SvUV(ST(5)); }
		if (items > 6) { perm_effect = (bool) SvTRUE(ST(6)); }
		if (items > 7) {
			if (sv_derived_from(ST(7), "Client")) {
				IV tmp = SvIV((SV *)SvRV(ST(7)));
				client = INT2PTR(Client *, tmp);
			}
			else {
				nullclient = true;
			}
			if (client == nullptr) {
				nullclient = true;
			}
		}
		if (items > 8) { caster_id = (uint32)SvUV(ST(8)); }
		if (items > 9) { target_id = (uint32)SvUV(ST(9)); }
		
		if (nullclient) {
			THIS->SendSpellEffect(effect, duration, finish_delay, zone_wide, unk20, perm_effect, 0, caster_id, target_id);
		}
		else {
			THIS->SendSpellEffect(effect, duration, finish_delay, zone_wide, unk20, perm_effect, client, caster_id, target_id);
		}

	}
	XSRETURN_EMPTY;
}


XS(XS_Mob_TempName); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_TempName) {
	dXSARGS;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Mob::TempName(THIS, string name)"); // @categories Script Utility
	{
		Mob  *THIS;
		char *name = nullptr;
		VALIDATE_THIS_IS_MOB;
		if (items > 1) { name = (char *) SvPV_nolen(ST(1)); }

		THIS->TempName(name);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetItemStat); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetItemStat) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetItemStat(THIS, uint32 item_id, string stat)"); // @categories Inventory and Items, Stats and Attributes
	{
		Mob *THIS;
		int32  RETVAL;
		uint32 itemid = (uint32) SvUV(ST(1));
		Const_char *stat = (Const_char *) SvPV_nolen(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetItemStat(itemid, stat);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetGlobal);
XS(XS_Mob_GetGlobal) {
	dXSARGS;
	if (items < 2)
		Perl_croak(aTHX_ "Usage: GetGlobal(THIS, string var_name)");
	{
		Mob        *THIS;
		Const_char *varname = (Const_char *) SvPV_nolen(ST(1));
		std::string ret_val = "Undefined";
		Const_char *RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		if (THIS->GetGlobal(varname) != "Undefined")
			ret_val = THIS->GetGlobal(varname);

		RETVAL = ret_val.c_str();
		sv_setpv(TARG, RETVAL);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_SetGlobal);
XS(XS_Mob_SetGlobal) {
	dXSARGS;
	if (items < 5 || items > 6)
		Perl_croak(aTHX_ "Usage: SetGlobal(THIS, string var_name, string new_value, int options, string duration, [Mob* other = nullptr])");
	{
		Mob  *THIS;
		char *varname  = (char *) SvPV_nolen(ST(1));
		char *newvalue = (char *) SvPV_nolen(ST(2));
		int options = (int) SvIV(ST(3));
		char *duration = (char *) SvPV_nolen(ST(4));
		Mob  *other    = nullptr;
		VALIDATE_THIS_IS_MOB;
		if (items > 5) {
			if (sv_derived_from(ST(5), "Mob")) {
				IV tmp = SvIV((SV *) SvRV(ST(5)));
				other = INT2PTR(Mob *, tmp);
			} else
				Perl_croak(aTHX_ "THIS is not of type Mob");
			if (other == nullptr)
				Perl_croak(aTHX_ "THIS is nullptr, avoiding crash.");
		}

		THIS->SetGlobal(varname, newvalue, options, duration, other);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_TarGlobal);
XS(XS_Mob_TarGlobal) {
	dXSARGS;
	if (items != 7)
		Perl_croak(aTHX_ "Usage: TarGlobal(THIS, string var_name, string value, string duration, int npc_id, int character_id, int zone_id)");
	{
		Mob  *THIS;
		char *varname  = (char *) SvPV_nolen(ST(1));
		char *value    = (char *) SvPV_nolen(ST(2));
		char *duration = (char *) SvPV_nolen(ST(3));
		int npcid  = (int) SvIV(ST(4));
		int charid = (int) SvIV(ST(5));
		int zoneid = (int) SvIV(ST(6));
		VALIDATE_THIS_IS_MOB;
		THIS->TarGlobal(varname, value, duration, npcid, charid, zoneid);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DelGlobal);
XS(XS_Mob_DelGlobal) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: DelGlobal(THIS, string var_name)");
	{
		Mob  *THIS;
		char *varname = (char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->DelGlobal(varname);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetSlotTint); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetSlotTint) {
	dXSARGS;
	if (items != 5)
		Perl_croak(aTHX_ "Usage: Mob::SetSlotTint(THIS, uint8 material_slot, uint8 red_tint, uint8 green_tint, uint8 blue_tint)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 material_slot = (uint8) SvIV(ST(1));
		uint8 red_tint      = (uint8) SvIV(ST(2));
		uint8 green_tint    = (uint8) SvIV(ST(3));
		uint8 blue_tint     = (uint8) SvIV(ST(4));
		VALIDATE_THIS_IS_MOB;
		THIS->SetSlotTint(material_slot, red_tint, green_tint, blue_tint);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_WearChange); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_WearChange) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::WearChange(THIS, uint8 material_slot, uint16 texture, [uint32 color = 0, uint32 hero_forge_model = 0])"); // @categories Script Utility
	{
		Mob *THIS;
		uint8  material_slot    = (uint8) SvIV(ST(1));
		uint16 texture          = (uint16) SvUV(ST(2));
		uint32 color            = 0;
		uint32 hero_forge_model = 0;
		VALIDATE_THIS_IS_MOB;
		if (items > 3) {
			color = (uint32) SvUV(ST(3));
		}
		if (items > 4) {
			hero_forge_model = (uint32) SvUV(ST(3));
		}

		THIS->WearChange(material_slot, texture, color, hero_forge_model);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DoKnockback); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DoKnockback) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Mob::DoKnockback(THIS, Mob* caster, uint32 push_back_amount, uint32 push_up_amount)"); // @categories Script Utility
	{
		Mob *THIS;
		Mob *caster;
		uint32 push_back = (uint16) SvUV(ST(2));
		uint32 push_up   = (uint16) SvUV(ST(2));
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			caster = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "caster is not of type Mob");
		if (caster == nullptr)
			Perl_croak(aTHX_ "caster is nullptr, avoiding crash.");

		THIS->DoKnockback(caster, push_back, push_up);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_RemoveNimbusEffect); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RemoveNimbusEffect) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::RemoveNimbusEffect(THIS, int32 effect_id)"); // @categories Script Utility
	{
		Mob *THIS;
		int32 effect_id = (int32) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->RemoveNimbusEffect(effect_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetRunning);
XS(XS_Mob_SetRunning) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetRunning(THIS, bool value)"); // @categories Script Utility
	{
		Mob *THIS;
		bool value = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetRunning(value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_IsRunning); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsRunning) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsRunning(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsRunning();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SetBodyType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetBodyType) {
	dXSARGS;
	if (items < 2 || items > 3)
		Perl_croak(aTHX_ "Usage: Mob::SetBodyType(THIS, int32 type, [bool overwrite_orig = false])"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 type           = (int32) SvIV(ST(1));
		bool  overwrite_orig = false;
		VALIDATE_THIS_IS_MOB;
		if (items == 3) {
			overwrite_orig = (bool) SvTRUE(ST(2));
		}

		THIS->SetBodyType((bodyType) type, overwrite_orig);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetDeltas); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetDeltas) {
	dXSARGS;
	if (items != 5)
		Perl_croak(aTHX_ "Usage: Mob::SetDeltas(THIS, float delta_x, float delta_y, float delta_z, float delta_h)"); // @categories Script Utility
	{
		Mob *THIS;
		auto delta = glm::vec4((float) SvNV(ST(1)), (float) SvNV(ST(2)), (float) SvNV(ST(3)), (float) SvNV(ST(4)));
		VALIDATE_THIS_IS_MOB;
		THIS->SetDelta(delta);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetLD);
XS(XS_Mob_SetLD) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetLD(THIS, bool value)"); // @categories Script Utility
	{
		Mob *THIS;
		bool value = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SendAppearancePacket(AT_Linkdead, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetTargetable); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetTargetable) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetTargetable(THIS, bool targetable)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool on = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetTargetable(on);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ModSkillDmgTaken); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ModSkillDmgTaken) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::ModSkillDmgTaken(THIS, int skill, int16 value)"); // @categories Skills and Recipes, Script Utility
	{
		Mob *THIS;
		EQ::skills::SkillType skill_num = (EQ::skills::SkillType) SvUV(ST(1));
		int16                    value     = (int16) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		THIS->ModSkillDmgTaken(skill_num, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetModSkillDmgTaken); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetModSkillDmgTaken) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetModSkillDmgTaken(THIS, int skill_id)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int16                    RETVAL;
		dXSTARG;
		EQ::skills::SkillType skill_num = (EQ::skills::SkillType) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetModSkillDmgTaken(skill_num);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSkillDmgTaken); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSkillDmgTaken) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetSkillDmgTaken(THIS, int skill_id)"); // @categories Skills and Recipes, Script Utility
	{
		Mob *THIS;
		int32                    RETVAL;
		dXSTARG;
		EQ::skills::SkillType skill_num = (EQ::skills::SkillType) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSkillDmgTaken(skill_num);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetAllowBeneficial);
XS(XS_Mob_SetAllowBeneficial) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetAllowBeneficial(THIS, bool value)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool value = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetAllowBeneficial(value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetAllowBeneficial); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetAllowBeneficial) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetAllowBeneficial(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetAllowBeneficial();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsBeneficialAllowed);
XS(XS_Mob_IsBeneficialAllowed) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::IsBeneficialAllowed(THIS, Mob* target)"); // @categories Stats and Attributes
	{
		dXSTARG;
		Mob *THIS;
		Mob *target;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");
		if (target == nullptr)
			Perl_croak(aTHX_ "target is nullptr, avoiding crash.");

		RETVAL = THIS->IsBeneficialAllowed(target);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_ModVulnerability); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ModVulnerability) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::ModVulnerability(THIS, uint8 resist, int16 value)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 resist = (uint8) SvIV(ST(1));
		int16 value  = (int16) SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		THIS->ModVulnerability(resist, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetModVulnerability); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetModVulnerability) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetModVulnerability(THIS, uint8 resist)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		uint8 resist = (uint8) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetModVulnerability(resist);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_DoMeleeSkillAttackDmg); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DoMeleeSkillAttackDmg) {
	dXSARGS;
	if (items != 7)
		Perl_croak(aTHX_ "Usage: Mob::DoMeleeSkillAttackDmg(THIS, Mob* target, uint16 weapon_damage, int skill, int16 chance_mod, int16 focus, uint8 can_riposte)"); // @categories Script Utility, Skills and Attributes
	{
		Mob *THIS;
		Mob *target;
		uint16                   weapon_damage = (uint16) SvIV(ST(2));
		EQ::skills::SkillType skill         = (EQ::skills::SkillType) SvUV(ST(3));
		int16                    chance_mod    = (int16) SvIV(ST(4));
		int16                    focus         = (int16) SvIV(ST(5));
		uint8                    CanRiposte    = (uint8) SvIV(ST(6));
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");
		if (target == nullptr)
			Perl_croak(aTHX_ "target is nullptr, avoiding crash.");

		THIS->DoMeleeSkillAttackDmg(target, weapon_damage, skill, chance_mod, focus, CanRiposte);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DoArcheryAttackDmg); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DoArcheryAttackDmg) {
	dXSARGS;
	if (items != 7)
		Perl_croak(aTHX_ "Usage: Mob::DoArcheryAttackDmg(THIS, Mob* target, [range_weapon_item_instance = nullptr], [ammo_item_instance = nullptr], uint16 weapon_damage, int16 chance_mod, int16 focus)"); // @categories Script Utility, Skills and Attributes
	{
		Mob                 *THIS;
		Mob                 *target;
		EQ::ItemInstance *RangeWeapon = nullptr;
		EQ::ItemInstance *Ammo        = nullptr;
		uint16 weapon_damage = (uint16) SvIV(ST(4));
		int16  chance_mod    = (int16) SvIV(ST(5));
		int16  focus         = (int16) SvIV(ST(6));
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");
		if (target == nullptr)
			Perl_croak(aTHX_ "target is nullptr, avoiding crash.");

		THIS->DoArcheryAttackDmg(target, RangeWeapon, Ammo, weapon_damage, chance_mod, focus);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_DoThrowingAttackDmg); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_DoThrowingAttackDmg) {
	dXSARGS;
	if (items != 7)
		Perl_croak(aTHX_ "Usage: Mob::DoThrowingAttackDmg(THIS, Mob* target, [range_weapon_item_instance = nullptr], [ammo_item_instance = nullptr], uint16 weapon_damage, int16 chance_mod, int16 focus)"); // @categories Script Utility, Skills and Attributes
	{
		Mob                 *THIS;
		Mob                 *target;
		EQ::ItemInstance *RangeWeapon = nullptr;
		EQ::ItemData     *item        = nullptr;
		uint16 weapon_damage = (uint16) SvIV(ST(4));
		int16  chance_mod    = (int16) SvIV(ST(5));
		int16  focus         = (int16) SvIV(ST(6));
		VALIDATE_THIS_IS_MOB;
		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV *) SvRV(ST(1)));
			target = INT2PTR(Mob *, tmp);
		} else
			Perl_croak(aTHX_ "target is not of type Mob");
		if (target == nullptr)
			Perl_croak(aTHX_ "target is nullptr, avoiding crash.");

		THIS->DoThrowingAttackDmg(target, RangeWeapon, item, weapon_damage, chance_mod, focus);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetDisableMelee);
XS(XS_Mob_SetDisableMelee) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetDisableMelee(THIS, bool value)"); // @categories Script Utility, Stats and Attributes
	{
		Mob *THIS;
		bool value = (bool) SvTRUE(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetDisableMelee(value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_IsMeleeDisabled); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_IsMeleeDisabled) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsMeleeDisabled(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsMeleeDisabled();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SetFlurryChance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetFlurryChance) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::SetFlurryChance(THIS, uint8 value)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 value = (uint8) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->SetFlurryChance(value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetFlurryChance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetFlurryChance) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetFlurryChance(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetFlurryChance();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSpellStat); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSpellStat) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::GetSpellStat(THIS, uint32 spell_id, string stat, uint8 slot)"); // @categories Spells and Disciplines
	{
		Mob *THIS;
		int32  RETVAL;
		uint32 spellid = (uint32) SvUV(ST(1));
		Const_char *stat = (Const_char *) SvPV_nolen(ST(2));
		uint8 slot = (uint8) SvUV(ST(3));
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		if (items > 4) { slot = 0; }


		RETVAL = THIS->GetSpellStat(spellid, stat, slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSpecialAbility); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSpecialAbility) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetSpecialAbility(THIS, int special_ability)"); // @categories Stats and Attributes
	{
		int RETVAL;
		Mob *THIS;
		int ability = SvIV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSpecialAbility(ability);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetSpecialAbilityParam); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetSpecialAbilityParam) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::GetSpecialAbilityParam(THIS, int special_ability, int param)"); // @categories Stats and Attributes
	{
		int RETVAL;
		Mob *THIS;
		int ability = SvIV(ST(1));
		int param   = SvIV(ST(2));
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetSpecialAbilityParam(ability, param);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SetSpecialAbility); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetSpecialAbility) {
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: Mob::SetSpecialAbility(THIS, int ability, int value)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int ability = SvIV(ST(1));
		int value   = SvIV(ST(2));
		VALIDATE_THIS_IS_MOB;
		THIS->SetSpecialAbility(ability, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_SetSpecialAbilityParam); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_SetSpecialAbilityParam) {
	dXSARGS;
	if (items != 4)
		Perl_croak(aTHX_ "Usage: Mob::SetSpecialAbilityParam(THIS, int ability, int param, int value)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int ability = SvIV(ST(1));
		int param   = SvIV(ST(2));
		int value   = SvIV(ST(3));
		VALIDATE_THIS_IS_MOB;
		THIS->SetSpecialAbilityParam(ability, param, value);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ClearSpecialAbilities); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ClearSpecialAbilities) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::ClearSpecialAbilities(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->ClearSpecialAbilities();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ProcessSpecialAbilities); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ProcessSpecialAbilities) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::ProcessSpecialAbilities(THIS, string str)"); // @categories Script Utility
	{
		Mob *THIS;
		const char *str = (const char *) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->ProcessSpecialAbilities(str);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_CanClassEquipItem); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanClassEquipItem) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::CanClassEquipItem(THIS, uint32 item_id)"); // @categories Inventory and Items, Script Utility
	{
		Mob *THIS;
		bool   RETVAL;
		uint32 item_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanClassEquipItem(item_id);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsFeared);
XS(XS_Mob_IsFeared) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsFeared(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsFeared();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsBlind);
XS(XS_Mob_IsBlind) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsBlind(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsBlind();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SeeInvisible);
XS(XS_Mob_SeeInvisible) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::SeeInvisible(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->SeeInvisible();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_SeeInvisibleUndead);
XS(XS_Mob_SeeInvisibleUndead) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::SeeInvisibleUndead(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->SeeInvisibleUndead();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SeeHide);
XS(XS_Mob_SeeHide) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::SeeHide(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->SeeHide();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_SeeImprovedHide);
XS(XS_Mob_SeeImprovedHide) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::SeeImprovedHide(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->SeeImprovedHide();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetNimbusEffect1);
XS(XS_Mob_GetNimbusEffect1) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetNimbusEffect1(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetNimbusEffect1();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetNimbusEffect2);
XS(XS_Mob_GetNimbusEffect2) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetNimbusEffect2(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetNimbusEffect2();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetNimbusEffect3);
XS(XS_Mob_GetNimbusEffect3) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetNimbusEffect3(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		uint8 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetNimbusEffect3();
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsTargetable);
XS(XS_Mob_IsTargetable) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsTargetable(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsTargetable();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_HasShieldEquiped);
XS(XS_Mob_HasShieldEquiped) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HasShieldEquiped(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasShieldEquiped();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_HasTwoHandBluntEquiped);
XS(XS_Mob_HasTwoHandBluntEquiped) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HasTwoHandBluntEquiped(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasTwoHandBluntEquiped();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_HasTwoHanderEquipped);
XS(XS_Mob_HasTwoHanderEquipped) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HasTwoHanderEquipped(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasTwoHanderEquipped();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHerosForgeModel);
XS(XS_Mob_GetHerosForgeModel) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetHerosForgeModel(THIS, uint8 material_slot)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		uint8 material_slot = (uint8) SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHerosForgeModel(material_slot);
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_IsEliteMaterialItem);
XS(XS_Mob_IsEliteMaterialItem) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::IsEliteMaterialItem(THIS, uint8 material_slot)"); // @categories Script Utility, Stats and Attributes
	{
		Mob *THIS;
		uint32 RETVAL;
		uint8  material_slot = (uint8) SvUV(ST(1));
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsEliteMaterialItem(material_slot);
		XSprePUSH;
		PUSHu((UV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBaseSize);
XS(XS_Mob_GetBaseSize) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBaseSize(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		float RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetBaseSize();
		XSprePUSH;
		PUSHn((double) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_HasOwner);
XS(XS_Mob_HasOwner) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HasOwner(THIS)"); // @categories Pet
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasOwner();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsPet);
XS(XS_Mob_IsPet) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsPet(THIS)"); // @categories Pet
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsPet();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_HasPet);
XS(XS_Mob_HasPet) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::HasPet(THIS)"); // @categories Pet
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->HasPet();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_RemovePet);
XS(XS_Mob_RemovePet) {
	dXSARGS;
	if (items != 1) {
		Perl_croak(aTHX_ "Usage: Mob::RemovePet(THIS)"); // @categories Pet
	}

	Mob* THIS;
	VALIDATE_THIS_IS_MOB;

	THIS->SetPet(nullptr);

	XSRETURN_EMPTY;
}

XS(XS_Mob_SetPet);
XS(XS_Mob_SetPet) {
	dXSARGS;
	if (items != 2) {
		Perl_croak(aTHX_ "Usage: Mob::SetPet(THIS, Mob* new_pet)"); // @categories Pet
	}

	Mob* THIS;
	VALIDATE_THIS_IS_MOB;

	Mob* new_pet = nullptr; // passing null or invalid new_pet removes pet
	if (sv_derived_from(ST(1), "Mob"))
	{
		IV tmp = SvIV((SV*)SvRV(ST(1)));
		new_pet = INT2PTR(Mob*, tmp);
	}

	THIS->SetPet(new_pet);

	XSRETURN_EMPTY;
}

XS(XS_Mob_IsSilenced);
XS(XS_Mob_IsSilenced) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsSilenced(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsSilenced();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_IsAmnesiad);
XS(XS_Mob_IsAmnesiad) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsAmnesiad(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsAmnesiad();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetMeleeMitigation);
XS(XS_Mob_GetMeleeMitigation) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetMeleeMitigation(THIS)"); // @categories Stats and Attributes
	{
		Mob *THIS;
		int32 RETVAL;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetMeleeMitigation();
		XSprePUSH;
		PUSHi((IV) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_TryMoveAlong);
XS(XS_Mob_TryMoveAlong) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::TryMoveAlong(THIS, float distance, float angle, bool send)"); // @categories Script Utility
	{
		Mob *THIS;
		float distance = (float) SvNV(ST(1));
		float angle    = (float) SvNV(ST(2));
		bool  send     = true;
		VALIDATE_THIS_IS_MOB;
		if (items == 4)
			send = (bool) SvTRUE(ST(3));

		THIS->TryMoveAlong(distance, angle, send);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetClassName);
XS(XS_Mob_GetClassName) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetClassName(THIS)");
	{
		Mob* THIS;
		Const_char *class_name;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		class_name = GetClassIDName(THIS->GetClass());
		sv_setpv(TARG, class_name);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_GetRaceName);
XS(XS_Mob_GetRaceName) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetRaceName(THIS)");
	{
		Mob* THIS;
		Const_char *race_name;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		race_name = GetRaceIDName(THIS->GetRace());
		sv_setpv(TARG, race_name);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_DeleteBucket);
XS(XS_Mob_DeleteBucket) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::DeleteBucket(THIS, std::string bucket_name)"); // @categories Script Utility
	{
		Mob* THIS;
		std::string bucket_name = (std::string) SvPV_nolen(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->DeleteBucket(bucket_name);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetBucket);
XS(XS_Mob_GetBucket) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetBucket(THIS, std::string bucket_name)"); // @categories Script Utility
	{
		Mob* THIS;
		dXSTARG;
		std::string bucket_name = (std::string) SvPV_nolen(ST(1));
		std::string bucket_value;
		VALIDATE_THIS_IS_MOB;
		bucket_value = THIS->GetBucket(bucket_name);
		sv_setpv(TARG, bucket_value.c_str());
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBucketExpires);
XS(XS_Mob_GetBucketExpires) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetBucketExpires(THIS, std::string bucket_name)"); // @categories Script Utility
	{
		Mob* THIS;
		dXSTARG;
		std::string bucket_name = (std::string) SvPV_nolen(ST(1));
		std::string bucket_expiration;
		VALIDATE_THIS_IS_MOB;
		bucket_expiration = THIS->GetBucketExpires(bucket_name);
		sv_setpv(TARG, bucket_expiration.c_str());
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBucketKey);
XS(XS_Mob_GetBucketKey) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetBucketKey(THIS)"); // @categories Script Utility
	{
		Mob* THIS;
		dXSTARG;
		std::string bucket_key;
		VALIDATE_THIS_IS_MOB;
		bucket_key = THIS->GetBucketKey();
		sv_setpv(TARG, bucket_key.c_str());
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_GetBucketRemaining);
XS(XS_Mob_GetBucketRemaining) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::GetBucketRemaining(THIS, std::string bucket_name)"); // @categories Script Utility
	{
		Mob* THIS;
		dXSTARG;
		std::string bucket_name = (std::string) SvPV_nolen(ST(1));
		std::string bucket_remaining;
		VALIDATE_THIS_IS_MOB;
		bucket_remaining = THIS->GetBucketRemaining(bucket_name);
		sv_setpv(TARG, bucket_remaining.c_str());
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_SetBucket);
XS(XS_Mob_SetBucket) {
	dXSARGS;
	if (items < 3 || items > 4)
		Perl_croak(aTHX_ "Usage: Mob::SetBucket(THIS, std::string bucket_name, std::string bucket_value, [std::string expiration])"); // @categories Script Utility
	{
		Mob* THIS;
		std::string key = (std::string) SvPV_nolen(ST(1));
		std::string value = (std::string) SvPV_nolen(ST(2));
		std::string expiration;
		VALIDATE_THIS_IS_MOB;
		if (items == 4)
			expiration = (std::string) SvPV_nolen(ST(3));

		THIS->SetBucket(key, value, expiration);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_IsHorse);
XS(XS_Mob_IsHorse) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::IsHorse(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		bool RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->IsHorse();
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHateListByDistance); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateListByDistance) {
	dXSARGS;
	int num_entries = 0;
	if (items < 1 || items > 2)
		Perl_croak(aTHX_ "Usage: Mob::GetHateListByDistance(THIS, int distance)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		int distance = 0;
		VALIDATE_THIS_IS_MOB;
		if (items == 2)
			distance = (int) SvIV(ST(1));

		auto list = THIS->GetHateListByDistance(distance);
		for (auto hate_entry : list) {
			ST(0) = sv_newmortal();
			sv_setref_pv(ST(0), "HateEntry", (void *) hate_entry);
			XPUSHs(ST(0));
			num_entries++;
		}
	}
	XSRETURN(num_entries);
}

XS(XS_Mob_GetHateClosest); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateClosest) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateClosest(THIS)"); // @categories Hate and Aggro
	{
		Mob *THIS;
		Mob *closest_mob;
		VALIDATE_THIS_IS_MOB;
		closest_mob = THIS->GetHateClosest();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void *) closest_mob);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetLastName); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetLastName) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetLastName(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		Const_char *last_name;
		dXSTARG;
		VALIDATE_THIS_IS_MOB;
		last_name = THIS->GetLastName();
		sv_setpv(TARG, last_name);
		XSprePUSH;
		PUSHTARG;
	}
	XSRETURN(1);
}

XS(XS_Mob_CanRaceEquipItem); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CanRaceEquipItem) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::CanRaceEquipItem(THIS, uint32 item_id)"); // @categories Inventory and Items, Script Utility
	{
		Mob *THIS;
		bool   RETVAL;
		uint32 item_id = (uint32) SvUV(ST(1));
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CanRaceEquipItem(item_id);
		ST(0) = boolSV(RETVAL);
		sv_2mortal(ST(0));
	}
	XSRETURN(1);
}

XS(XS_Mob_RemoveAllNimbusEffects); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_RemoveAllNimbusEffects) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::RemoveAllNimbusEffects(THIS)"); // @categories Script Utility
	{
		Mob *THIS;
		VALIDATE_THIS_IS_MOB;
		THIS->RemoveAllNimbusEffects();
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_AddNimbusEffect);
XS(XS_Mob_AddNimbusEffect) {
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: Mob::AddNimbusEffect(THIS, int effect_id)"); // @categories Script Utility
	{
		Mob* THIS;
		int effect_id = (int) SvIV(ST(1));
		VALIDATE_THIS_IS_MOB;
		THIS->AddNimbusEffect(effect_id);
	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_ShieldAbility); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_ShieldAbility) {
	dXSARGS;
	if (items < 2 || items > 6)
		Perl_croak(aTHX_ "Usage: Mob::ShieldAbility(THIS, uint32 target_id, [int32 shielder__max_distance = 15], [int32 shield_duration = 12000], [int32 shield_target_mitigation= 50], [int32 shielder_mitigation = 50], [bool use_aa = false], bool [can_shield_npc = true]"); // @categories Spells and Disciplines
	{
		Mob    *THIS;
		uint32 target_id = (uint32)SvUV(ST(1));
		int32  shielder_max_distance = (int32)SvUV(ST(2));
		int32  shield_duration = (int32)SvUV(ST(3));
		int32  shield_target_mitigation = (int32)SvUV(ST(4));
		int32  shielder_mitigation = (int32)SvUV(ST(5));
		bool   use_aa = (bool)SvTRUE(ST(6));
		bool   can_shield_npc = (bool)SvTRUE(ST(7));

		VALIDATE_THIS_IS_MOB;
		if (items < 3) {
			shielder_max_distance = 15;
		}

		if (items < 4) {
			shield_duration = 12000;
		}

		if (items < 5) {
			shield_target_mitigation = 50;
		}

		if (items < 6) {
			shielder_mitigation = 50;
		}

		if (items < 7) {
			use_aa = false;
		}

		if (items < 8) {
			can_shield_npc = true;
		}
		THIS->ShieldAbility(target_id, shielder_max_distance, shield_duration, shield_duration, shield_duration, use_aa, can_shield_npc);

	}
	XSRETURN_EMPTY;
}

XS(XS_Mob_GetHateRandomClient); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateRandomClient) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateRandomClient(THIS)"); // @categories Hate and Aggro
	{
		Mob* THIS;
		Client* RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHateRandomClient();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Client", (void *) RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHateRandomNPC); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateRandomNPC) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateRandomNPC(THIS)"); // @categories Hate and Aggro
	{
		Mob* THIS;
		NPC* RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHateRandomNPC();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "NPC", (void *) RETVAL);
	}
	XSRETURN(1);
}

#ifdef BOTS
XS(XS_Mob_CastToBot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_CastToBot)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::CastToBot(THIS)");
	{
		Mob* THIS;
		Bot* RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->CastToBot();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Bot", (void*)RETVAL);
	}
	XSRETURN(1);
}

XS(XS_Mob_GetHateRandomBot); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mob_GetHateRandomBot) {
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: Mob::GetHateRandomBot(THIS)"); // @categories Hate and Aggro
	{
		Mob* THIS;
		Bot* RETVAL;
		VALIDATE_THIS_IS_MOB;
		RETVAL = THIS->GetHateRandomBot();
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Bot", (void *) RETVAL);
	}
	XSRETURN(1);
}
#endif

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Mob); /* prototype to pass -Wmissing-prototypes */
XS(boot_Mob) {
	dXSARGS;
	char file[256];
	strncpy(file, __FILE__, 256);
	file[255] = 0;

	if (items != 1)
		fprintf(stderr, "boot_quest does not take any arguments.");
	char buf[128];

	//add the strcpy stuff to get rid of const warnings....

	XS_VERSION_BOOTCHECK;
	newXSproto(strcpy(buf, "AddFeignMemory"), XS_Mob_AddFeignMemory, file, "$$");
	newXSproto(strcpy(buf, "AddNimbusEffect"), XS_Mob_AddNimbusEffect, file, "$$");
	newXSproto(strcpy(buf, "AddToHateList"), XS_Mob_AddToHateList, file, "$$;$$$$$");
	newXSproto(strcpy(buf, "Attack"), XS_Mob_Attack, file, "$$;$$");
	newXSproto(strcpy(buf, "BehindMob"), XS_Mob_BehindMob, file, "$;$$$");
	newXSproto(strcpy(buf, "BuffCount"), XS_Mob_BuffCount, file, "$");
	newXSproto(strcpy(buf, "BuffFadeAll"), XS_Mob_BuffFadeAll, file, "$");
	newXSproto(strcpy(buf, "BuffFadeByEffect"), XS_Mob_BuffFadeByEffect, file, "$$;$");
	newXSproto(strcpy(buf, "BuffFadeBySlot"), XS_Mob_BuffFadeBySlot, file, "$$;$");
	newXSproto(strcpy(buf, "BuffFadeBySpellID"), XS_Mob_BuffFadeBySpellID, file, "$$");
	newXSproto(strcpy(buf, "CalculateDistance"), XS_Mob_CalculateDistance, file, "$$$$");
	newXSproto(strcpy(buf, "CalculateHeadingToTarget"), XS_Mob_CalculateHeadingToTarget, file, "$$$");
	newXSproto(strcpy(buf, "CameraEffect"), XS_Mob_CameraEffect, file, "$$;$$$");
	newXSproto(strcpy(buf, "CanBuffStack"), XS_Mob_CanBuffStack, file, "$$$;$");
	newXSproto(strcpy(buf, "CanClassEquipItem"), XS_Mob_CanClassEquipItem, file, "$$");
	newXSproto(strcpy(buf, "CanRaceEquipItem"), XS_Mob_CanRaceEquipItem, file, "$$");
	newXSproto(strcpy(buf, "CanThisClassDodge"), XS_Mob_CanThisClassDodge, file, "$");
	newXSproto(strcpy(buf, "CanThisClassDoubleAttack"), XS_Mob_CanThisClassDoubleAttack, file, "$");
	newXSproto(strcpy(buf, "CanThisClassDualWield"), XS_Mob_CanThisClassDualWield, file, "$");
	newXSproto(strcpy(buf, "CanThisClassParry"), XS_Mob_CanThisClassParry, file, "$");
	newXSproto(strcpy(buf, "CanThisClassRiposte"), XS_Mob_CanThisClassRiposte, file, "$");
	newXSproto(strcpy(buf, "CastSpell"), XS_Mob_CastSpell, file, "$$$;$$$");
#ifdef BOTS
	newXSproto(strcpy(buf, "CastToBot"), XS_Mob_CastToBot, file, "$");
#endif
	newXSproto(strcpy(buf, "CastToClient"), XS_Mob_CastToClient, file, "$");
	newXSproto(strcpy(buf, "CastToCorpse"), XS_Mob_CastToCorpse, file, "$");
	newXSproto(strcpy(buf, "CastToMob"), XS_Mob_CastToMob, file, "$");
	newXSproto(strcpy(buf, "CastToNPC"), XS_Mob_CastToNPC, file, "$");
	newXSproto(strcpy(buf, "CastingSpellID"), XS_Mob_CastingSpellID, file, "$");
	newXSproto(strcpy(buf, "ChangeSize"), XS_Mob_ChangeSize, file, "$$;$");
	newXSproto(strcpy(buf, "Charmed"), XS_Mob_Charmed, file, "$");
	newXSproto(strcpy(buf, "CheckAggro"), XS_Mob_CheckAggro, file, "$$");
	newXSproto(strcpy(buf, "CheckAggroAmount"), XS_Mob_CheckAggroAmount, file, "$$");
	newXSproto(strcpy(buf, "CheckHealAggroAmount"), XS_Mob_CheckHealAggroAmount, file, "$$");
	newXSproto(strcpy(buf, "CheckLoS"), XS_Mob_CheckLoS, file, "$$");
	newXSproto(strcpy(buf, "CheckLoSToLoc"), XS_Mob_CheckLoSToLoc, file, "$$$$;$");
	newXSproto(strcpy(buf, "ClearFeignMemory"), XS_Mob_ClearFeignMemory, file, "$");
	newXSproto(strcpy(buf, "ClearSpecialAbilities"), XS_Mob_ClearSpecialAbilities, file, "$");
	newXSproto(strcpy(buf, "CombatRange"), XS_Mob_CombatRange, file, "$$");
	newXSproto(strcpy(buf, "Damage"), XS_Mob_Damage, file, "$$$$$;$$$");
	newXSproto(strcpy(buf, "DelGlobal"), XS_Mob_DelGlobal, file, "$$");
	newXSproto(strcpy(buf, "DeleteBucket"), XS_Mob_DeleteBucket, file, "$$");
	newXSproto(strcpy(buf, "Depop"), XS_Mob_Depop, file, "$;$");
	newXSproto(strcpy(buf, "DivineAura"), XS_Mob_DivineAura, file, "$");
	newXSproto(strcpy(buf, "DoAnim"), XS_Mob_DoAnim, file, "$$;$");
	newXSproto(strcpy(buf, "DoArcheryAttackDmg"), XS_Mob_DoArcheryAttackDmg, file, "$$$$$$$");
	newXSproto(strcpy(buf, "DoKnockback"), XS_Mob_DoKnockback, file, "$$$$");
	newXSproto(strcpy(buf, "DoMeleeSkillAttackDmg"), XS_Mob_DoMeleeSkillAttackDmg, file, "$$$$$$$");
	newXSproto(strcpy(buf, "DoSpecialAttackDamage"), XS_Mob_DoSpecialAttackDamage, file, "$$$$;$$");
	newXSproto(strcpy(buf, "DoThrowingAttackDmg"), XS_Mob_DoThrowingAttackDmg, file, "$$$$$$$");
	newXSproto(strcpy(buf, "DontBuffMeBefore"), XS_Mob_DontBuffMeBefore, file, "$");
	newXSproto(strcpy(buf, "DontDotMeBefore"), XS_Mob_DontDotMeBefore, file, "$");
	newXSproto(strcpy(buf, "DontHealMeBefore"), XS_Mob_DontHealMeBefore, file, "$");
	newXSproto(strcpy(buf, "DontRootMeBefore"), XS_Mob_DontRootMeBefore, file, "$");
	newXSproto(strcpy(buf, "DontSnareMeBefore"), XS_Mob_DontSnareMeBefore, file, "$");
	newXSproto(strcpy(buf, "DoubleAggro"), XS_Mob_DoubleAggro, file, "$$");
	newXSproto(strcpy(buf, "Emote"), XS_Mob_Emote, file, "$$;@");
	newXSproto(strcpy(buf, "EntityVariableExists"), XS_Mob_EntityVariableExists, file, "$$");
	newXSproto(strcpy(buf, "FaceTarget"), XS_Mob_FaceTarget, file, "$;$$");
	newXSproto(strcpy(buf, "FindBuff"), XS_Mob_FindBuff, file, "$$");
	newXSproto(strcpy(buf, "FindBuffBySlot"), XS_Mob_FindBuffBySlot, file, "$$");
	newXSproto(strcpy(buf, "FindGroundZ"), XS_Mob_FindGroundZ, file, "$$$;$");
	newXSproto(strcpy(buf, "FindType"), XS_Mob_FindType, file, "$$;$$");
	newXSproto(strcpy(buf, "GMMove"), XS_Mob_GMMove, file, "$$$$;$");
	newXSproto(strcpy(buf, "Gate"), XS_Mob_Gate, file, "$");
	newXSproto(strcpy(buf, "GetAA"), XS_Mob_GetAA, file, "$$");
	newXSproto(strcpy(buf, "GetAAByAAID"), XS_Mob_GetAAByAAID, file, "$$");
	newXSproto(strcpy(buf, "GetAC"), XS_Mob_GetAC, file, "$");
	newXSproto(strcpy(buf, "GetAGI"), XS_Mob_GetAGI, file, "$");
	newXSproto(strcpy(buf, "GetATK"), XS_Mob_GetATK, file, "$");
	newXSproto(strcpy(buf, "GetActSpellCasttime"), XS_Mob_GetActSpellCasttime, file, "$$$");
	newXSproto(strcpy(buf, "GetActSpellCost"), XS_Mob_GetActSpellCost, file, "$$$");
	newXSproto(strcpy(buf, "GetActSpellDamage"), XS_Mob_GetActSpellDamage, file, "$$$");
	newXSproto(strcpy(buf, "GetActSpellDuration"), XS_Mob_GetActSpellDuration, file, "$$$");
	newXSproto(strcpy(buf, "GetActSpellHealing"), XS_Mob_GetActSpellHealing, file, "$$$");
	newXSproto(strcpy(buf, "GetActSpellRange"), XS_Mob_GetActSpellRange, file, "$$$");
	newXSproto(strcpy(buf, "GetAggroRange"), XS_Mob_GetAggroRange, file, "$");
	newXSproto(strcpy(buf, "GetAllowBeneficial"), XS_Mob_GetAllowBeneficial, file, "$$");
	newXSproto(strcpy(buf, "GetAppearance"), XS_Mob_GetAppearance, file, "$");
	newXSproto(strcpy(buf, "GetArmorTint"), XS_Mob_GetArmorTint, file, "$$");
	newXSproto(strcpy(buf, "GetAssistRange"), XS_Mob_GetAssistRange, file, "$");
	newXSproto(strcpy(buf, "GetBaseGender"), XS_Mob_GetBaseGender, file, "$");
	newXSproto(strcpy(buf, "GetBaseRace"), XS_Mob_GetBaseRace, file, "$");
	newXSproto(strcpy(buf, "GetBaseSize"), XS_Mob_GetBaseSize, file, "$");
	newXSproto(strcpy(buf, "GetBeard"), XS_Mob_GetBeard, file, "$");
	newXSproto(strcpy(buf, "GetBeardColor"), XS_Mob_GetBeardColor, file, "$");
	newXSproto(strcpy(buf, "GetBodyType"), XS_Mob_GetBodyType, file, "$");
	newXSproto(strcpy(buf, "GetBucket"), XS_Mob_GetBucket, file, "$$");
	newXSproto(strcpy(buf, "GetBucketExpires"), XS_Mob_GetBucketExpires, file, "$$");
	newXSproto(strcpy(buf, "GetBucketKey"), XS_Mob_GetBucketKey, file, "$");
	newXSproto(strcpy(buf, "GetBucketRemaining"), XS_Mob_GetBucketRemaining, file, "$$");
	newXSproto(strcpy(buf, "GetBuffSlotFromType"), XS_Mob_GetBuffSlotFromType, file, "$$");
	newXSproto(strcpy(buf, "GetCHA"), XS_Mob_GetCHA, file, "$");
	newXSproto(strcpy(buf, "GetCR"), XS_Mob_GetCR, file, "$");
	newXSproto(strcpy(buf, "GetCasterLevel"), XS_Mob_GetCasterLevel, file, "$$");
	newXSproto(strcpy(buf, "GetClass"), XS_Mob_GetClass, file, "$");
	newXSproto(strcpy(buf, "GetClassLevelFactor"), XS_Mob_GetClassLevelFactor, file, "$");
	newXSproto(strcpy(buf, "GetClassName"), XS_Mob_GetClassName, file, "$");
	newXSproto(strcpy(buf, "GetCleanName"), XS_Mob_GetCleanName, file, "$");
	newXSproto(strcpy(buf, "GetCorruption"), XS_Mob_GetCorruption, file, "$");
	newXSproto(strcpy(buf, "GetDEX"), XS_Mob_GetDEX, file, "$");
	newXSproto(strcpy(buf, "GetDR"), XS_Mob_GetDR, file, "$");
	newXSproto(strcpy(buf, "GetDamageAmount"), XS_Mob_GetDamageAmount, file, "$$");
	newXSproto(strcpy(buf, "GetDeity"), XS_Mob_GetDeity, file, "$");
	newXSproto(strcpy(buf, "GetDisplayAC"), XS_Mob_GetDisplayAC, file, "$");
	newXSproto(strcpy(buf, "GetDrakkinDetails"), XS_Mob_GetDrakkinDetails, file, "$");
	newXSproto(strcpy(buf, "GetDrakkinHeritage"), XS_Mob_GetDrakkinHeritage, file, "$");
	newXSproto(strcpy(buf, "GetDrakkinTattoo"), XS_Mob_GetDrakkinTattoo, file, "$");
	newXSproto(strcpy(buf, "GetEntityVariable"), XS_Mob_GetEntityVariable, file, "$$");
	newXSproto(strcpy(buf, "GetEquipment"), XS_Mob_GetEquipment, file, "$$");
	newXSproto(strcpy(buf, "GetEquipmentColor"), XS_Mob_GetEquipmentColor, file, "$$");
	newXSproto(strcpy(buf, "GetEquipmentMaterial"), XS_Mob_GetEquipmentMaterial, file, "$$");
	newXSproto(strcpy(buf, "GetEyeColor1"), XS_Mob_GetEyeColor1, file, "$");
	newXSproto(strcpy(buf, "GetEyeColor2"), XS_Mob_GetEyeColor2, file, "$");
	newXSproto(strcpy(buf, "GetFR"), XS_Mob_GetFR, file, "$");
	newXSproto(strcpy(buf, "GetFlurryChance"), XS_Mob_GetFlurryChance, file, "$");
	newXSproto(strcpy(buf, "GetFollowID"), XS_Mob_GetFollowID, file, "$");
	newXSproto(strcpy(buf, "GetGender"), XS_Mob_GetGender, file, "$");
	newXSproto(strcpy(buf, "GetGlobal"), XS_Mob_GetGlobal, file, "$$");
	newXSproto(strcpy(buf, "GetHP"), XS_Mob_GetHP, file, "$");
	newXSproto(strcpy(buf, "GetHPRatio"), XS_Mob_GetHPRatio, file, "$");
	newXSproto(strcpy(buf, "GetHairColor"), XS_Mob_GetHairColor, file, "$");
	newXSproto(strcpy(buf, "GetHairStyle"), XS_Mob_GetHairStyle, file, "$");
	newXSproto(strcpy(buf, "GetHandToHandDamage"), XS_Mob_GetHandToHandDamage, file, "$");
	newXSproto(strcpy(buf, "GetHandToHandDelay"), XS_Mob_GetHandToHandDelay, file, "$");
	newXSproto(strcpy(buf, "GetHaste"), XS_Mob_GetHaste, file, "$");
	newXSproto(strcpy(buf, "GetHateAmount"), XS_Mob_GetHateAmount, file, "$$;$");
	newXSproto(strcpy(buf, "GetHateClosest"), XS_Mob_GetHateClosest, file, "$");
	newXSproto(strcpy(buf, "GetHateDamageTop"), XS_Mob_GetHateDamageTop, file, "$$");
	newXSproto(strcpy(buf, "GetHateList"), XS_Mob_GetHateList, file, "$");
	newXSproto(strcpy(buf, "GetHateListByDistance"), XS_Mob_GetHateListByDistance, file, "$;$");
	newXSproto(strcpy(buf, "GetHateRandom"), XS_Mob_GetHateRandom, file, "$");
#ifdef BOTS
	newXSproto(strcpy(buf, "GetHateRandomBot"), XS_Mob_GetHateRandomBot, file, "$");
#endif
	newXSproto(strcpy(buf, "GetHateRandomClient"), XS_Mob_GetHateRandomClient, file, "$");
	newXSproto(strcpy(buf, "GetHateRandomNPC"), XS_Mob_GetHateRandomNPC, file, "$");
	newXSproto(strcpy(buf, "GetHateTop"), XS_Mob_GetHateTop, file, "$");
	newXSproto(strcpy(buf, "GetHeading"), XS_Mob_GetHeading, file, "$");
	newXSproto(strcpy(buf, "GetHelmTexture"), XS_Mob_GetHelmTexture, file, "$");
	newXSproto(strcpy(buf, "GetHerosForgeModel"), XS_Mob_GetHerosForgeModel, file, "$$");
	newXSproto(strcpy(buf, "GetID"), XS_Mob_GetID, file, "$");
	newXSproto(strcpy(buf, "GetINT"), XS_Mob_GetINT, file, "$");
	newXSproto(strcpy(buf, "GetInvul"), XS_Mob_GetInvul, file, "$");
	newXSproto(strcpy(buf, "GetItemHPBonuses"), XS_Mob_GetItemHPBonuses, file, "$");
	newXSproto(strcpy(buf, "GetItemStat"), XS_Mob_GetItemStat, file, "$$$");
	newXSproto(strcpy(buf, "GetLastName"), XS_Mob_GetLastName, file, "$");
	newXSproto(strcpy(buf, "GetLevel"), XS_Mob_GetLevel, file, "$");
	newXSproto(strcpy(buf, "GetLevelCon"), XS_Mob_GetLevelCon, file, "$$");
	newXSproto(strcpy(buf, "GetLevelHP"), XS_Mob_GetLevelHP, file, "$$");
	newXSproto(strcpy(buf, "GetLuclinFace"), XS_Mob_GetLuclinFace, file, "$");
	newXSproto(strcpy(buf, "GetMR"), XS_Mob_GetMR, file, "$");
	newXSproto(strcpy(buf, "GetMana"), XS_Mob_GetMana, file, "$");
	newXSproto(strcpy(buf, "GetManaRatio"), XS_Mob_GetManaRatio, file, "$");
	newXSproto(strcpy(buf, "GetMaxAGI"), XS_Mob_GetMaxAGI, file, "$");
	newXSproto(strcpy(buf, "GetMaxCHA"), XS_Mob_GetMaxCHA, file, "$");
	newXSproto(strcpy(buf, "GetMaxDEX"), XS_Mob_GetMaxDEX, file, "$");
	newXSproto(strcpy(buf, "GetMaxHP"), XS_Mob_GetMaxHP, file, "$");
	newXSproto(strcpy(buf, "GetMaxINT"), XS_Mob_GetMaxINT, file, "$");
	newXSproto(strcpy(buf, "GetMaxMana"), XS_Mob_GetMaxMana, file, "$");
	newXSproto(strcpy(buf, "GetMaxSTA"), XS_Mob_GetMaxSTA, file, "$");
	newXSproto(strcpy(buf, "GetMaxSTR"), XS_Mob_GetMaxSTR, file, "$");
	newXSproto(strcpy(buf, "GetMaxWIS"), XS_Mob_GetMaxWIS, file, "$");
	newXSproto(strcpy(buf, "GetMeleeMitigation"), XS_Mob_GetMeleeMitigation, file, "$");
	newXSproto(strcpy(buf, "GetModSkillDmgTaken"), XS_Mob_GetModSkillDmgTaken, file, "$$");
	newXSproto(strcpy(buf, "GetModVulnerability"), XS_Mob_GetModVulnerability, file, "$$");
	newXSproto(strcpy(buf, "GetNPCTypeID"), XS_Mob_GetNPCTypeID, file, "$");
	newXSproto(strcpy(buf, "GetName"), XS_Mob_GetName, file, "$");
	newXSproto(strcpy(buf, "GetNimbusEffect1"), XS_Mob_GetNimbusEffect1, file, "$");
	newXSproto(strcpy(buf, "GetNimbusEffect2"), XS_Mob_GetNimbusEffect2, file, "$");
	newXSproto(strcpy(buf, "GetNimbusEffect3"), XS_Mob_GetNimbusEffect3, file, "$");
	newXSproto(strcpy(buf, "GetOwnerID"), XS_Mob_GetOwnerID, file, "$");
	newXSproto(strcpy(buf, "GetPR"), XS_Mob_GetPR, file, "$");
	newXSproto(strcpy(buf, "GetPetID"), XS_Mob_GetPetID, file, "$");
	newXSproto(strcpy(buf, "GetPetOrder"), XS_Mob_GetPetOrder, file, "$");
	newXSproto(strcpy(buf, "GetPetType"), XS_Mob_GetPetType, file, "$");
	newXSproto(strcpy(buf, "GetPhR"), XS_Mob_GetPhR, file, "$");
	newXSproto(strcpy(buf, "GetRace"), XS_Mob_GetRace, file, "$");
	newXSproto(strcpy(buf, "GetRaceName"), XS_Mob_GetRaceName, file, "$");
	newXSproto(strcpy(buf, "GetResist"), XS_Mob_GetResist, file, "$$");
	newXSproto(strcpy(buf, "GetReverseFactionCon"), XS_Mob_GetReverseFactionCon, file, "$$");
	newXSproto(strcpy(buf, "GetRunAnimSpeed"), XS_Mob_GetRunAnimSpeed, file, "$");
	newXSproto(strcpy(buf, "GetRunspeed"), XS_Mob_GetRunspeed, file, "$");
	newXSproto(strcpy(buf, "GetSTA"), XS_Mob_GetSTA, file, "$");
	newXSproto(strcpy(buf, "GetSTR"), XS_Mob_GetSTR, file, "$");
	newXSproto(strcpy(buf, "GetSize"), XS_Mob_GetSize, file, "$");
	newXSproto(strcpy(buf, "GetSkill"), XS_Mob_GetSkill, file, "$$");
	newXSproto(strcpy(buf, "GetSkillDmgTaken"), XS_Mob_GetSkillDmgTaken, file, "$$");
	newXSproto(strcpy(buf, "GetSpecialAbility"), XS_Mob_GetSpecialAbility, file, "$$");
	newXSproto(strcpy(buf, "GetSpecialAbilityParam"), XS_Mob_GetSpecialAbilityParam, file, "$$$");
	newXSproto(strcpy(buf, "GetSpecializeSkillValue"), XS_Mob_GetSpecializeSkillValue, file, "$$");
	newXSproto(strcpy(buf, "GetSpellHPBonuses"), XS_Mob_GetSpellHPBonuses, file, "$");
	newXSproto(strcpy(buf, "GetSpellIDFromSlot"), XS_Mob_GetSpellIDFromSlot, file, "$$");
	newXSproto(strcpy(buf, "GetSpellStat"), XS_Mob_GetSpellStat, file, "$$$$");
	newXSproto(strcpy(buf, "GetTarget"), XS_Mob_GetTarget, file, "$");
	newXSproto(strcpy(buf, "GetTexture"), XS_Mob_GetTexture, file, "$");
	newXSproto(strcpy(buf, "GetWIS"), XS_Mob_GetWIS, file, "$");
	newXSproto(strcpy(buf, "GetWalkspeed"), XS_Mob_GetWalkspeed, file, "$");
	newXSproto(strcpy(buf, "GetWaypointH"), XS_Mob_GetWaypointH, file, "$");
	newXSproto(strcpy(buf, "GetWaypointID"), XS_Mob_GetWaypointID, file, "$");
	newXSproto(strcpy(buf, "GetWaypointPause"), XS_Mob_GetWaypointPause, file, "$");
	newXSproto(strcpy(buf, "GetWaypointX"), XS_Mob_GetWaypointX, file, "$");
	newXSproto(strcpy(buf, "GetWaypointY"), XS_Mob_GetWaypointY, file, "$");
	newXSproto(strcpy(buf, "GetWaypointZ"), XS_Mob_GetWaypointZ, file, "$");
	newXSproto(strcpy(buf, "GetX"), XS_Mob_GetX, file, "$");
	newXSproto(strcpy(buf, "GetY"), XS_Mob_GetY, file, "$");
	newXSproto(strcpy(buf, "GetZ"), XS_Mob_GetZ, file, "$");
	newXSproto(strcpy(buf, "GetZoneID"), XS_Mob_GetZoneID, file, "$");
	newXSproto(strcpy(buf, "GoToBind"), XS_Mob_GoToBind, file, "$");
	newXSproto(strcpy(buf, "HalveAggro"), XS_Mob_HalveAggro, file, "$$");
	newXSproto(strcpy(buf, "HasNPCSpecialAtk"), XS_Mob_HasNPCSpecialAtk, file, "$$");
	newXSproto(strcpy(buf, "HasOwner"), XS_Mob_HasOwner, file, "$");
	newXSproto(strcpy(buf, "HasPet"), XS_Mob_HasPet, file, "$");
	newXSproto(strcpy(buf, "HasProcs"), XS_Mob_HasProcs, file, "$");
	newXSproto(strcpy(buf, "HasShieldEquiped"), XS_Mob_HasShieldEquiped, file, "$");
	newXSproto(strcpy(buf, "HasTwoHandBluntEquiped"), XS_Mob_HasTwoHandBluntEquiped, file, "$");
	newXSproto(strcpy(buf, "HasTwoHanderEquipped"), XS_Mob_HasTwoHanderEquipped, file, "$");
	newXSproto(strcpy(buf, "HateSummon"), XS_Mob_HateSummon, file, "$");
	newXSproto(strcpy(buf, "Heal"), XS_Mob_Heal, file, "$");
	newXSproto(strcpy(buf, "HealDamage"), XS_Mob_HealDamage, file, "$$;$");
	newXSproto(strcpy(buf, "InterruptSpell"), XS_Mob_InterruptSpell, file, "$;$");
	newXSproto(strcpy(buf, "IsAIControlled"), XS_Mob_IsAIControlled, file, "$");
	newXSproto(strcpy(buf, "IsAmnesiad"), XS_Mob_IsAmnesiad, file, "$");
	newXSproto(strcpy(buf, "IsBeacon"), XS_Mob_IsBeacon, file, "$");
	newXSproto(strcpy(buf, "IsBeneficialAllowed"), XS_Mob_IsBeneficialAllowed, file, "$$");
	newXSproto(strcpy(buf, "IsBlind"), XS_Mob_IsBlind, file, "$");
	newXSproto(strcpy(buf, "IsBot"), XS_Mob_IsBot, file, "$");
	newXSproto(strcpy(buf, "IsCasting"), XS_Mob_IsCasting, file, "$");
	newXSproto(strcpy(buf, "IsClient"), XS_Mob_IsClient, file, "$");
	newXSproto(strcpy(buf, "IsCorpse"), XS_Mob_IsCorpse, file, "$");
	newXSproto(strcpy(buf, "IsDoor"), XS_Mob_IsDoor, file, "$");
	newXSproto(strcpy(buf, "IsEliteMaterialItem"), XS_Mob_IsEliteMaterialItem, file, "$$");
	newXSproto(strcpy(buf, "IsEngaged"), XS_Mob_IsEngaged, file, "$");
	newXSproto(strcpy(buf, "IsEnraged"), XS_Mob_IsEnraged, file, "$");
	newXSproto(strcpy(buf, "IsFeared"), XS_Mob_IsFeared, file, "$");
	newXSproto(strcpy(buf, "IsHorse"), XS_Mob_IsHorse, file, "$");
	newXSproto(strcpy(buf, "IsImmuneToSpell"), XS_Mob_IsImmuneToSpell, file, "$$$");
	newXSproto(strcpy(buf, "IsInvisible"), XS_Mob_IsInvisible, file, "$;$");
	newXSproto(strcpy(buf, "IsMeleeDisabled"), XS_Mob_IsMeleeDisabled, file, "$");
	newXSproto(strcpy(buf, "IsMezzed"), XS_Mob_IsMezzed, file, "$");
	newXSproto(strcpy(buf, "IsMob"), XS_Mob_IsMob, file, "$");
	newXSproto(strcpy(buf, "IsMoving"), XS_Mob_IsMoving, file, "$");
	newXSproto(strcpy(buf, "IsNPC"), XS_Mob_IsNPC, file, "$");
	newXSproto(strcpy(buf, "IsNPCCorpse"), XS_Mob_IsNPCCorpse, file, "$");
	newXSproto(strcpy(buf, "IsObject"), XS_Mob_IsObject, file, "$");
	newXSproto(strcpy(buf, "IsPet"), XS_Mob_IsPet, file, "$");
	newXSproto(strcpy(buf, "IsPlayerCorpse"), XS_Mob_IsPlayerCorpse, file, "$");
	newXSproto(strcpy(buf, "IsRoamer"), XS_Mob_IsRoamer, file, "$");
	newXSproto(strcpy(buf, "IsRooted"), XS_Mob_IsRooted, file, "$");
	newXSproto(strcpy(buf, "IsRunning"), XS_Mob_IsRunning, file, "$");
	newXSproto(strcpy(buf, "IsSilenced"), XS_Mob_IsSilenced, file, "$");
	newXSproto(strcpy(buf, "IsStunned"), XS_Mob_IsStunned, file, "$");
	newXSproto(strcpy(buf, "IsTargetable"), XS_Mob_IsTargetable, file, "$");
	newXSproto(strcpy(buf, "IsTargeted"), XS_Mob_IsTargeted, file, "$");
	newXSproto(strcpy(buf, "IsTrap"), XS_Mob_IsTrap, file, "$");
	newXSproto(strcpy(buf, "IsWarriorClass"), XS_Mob_IsWarriorClass, file, "$");
	newXSproto(strcpy(buf, "Kill"), XS_Mob_Kill, file, "$");
	newXSproto(strcpy(buf, "MakePet"), XS_Mob_MakePet, file, "$$$;$");
	newXSproto(strcpy(buf, "MakeTempPet"), XS_Mob_MakeTempPet, file, "$$;$$$$");
	newXSproto(strcpy(buf, "Mesmerize"), XS_Mob_Mesmerize, file, "$");
	newXSproto(strcpy(buf, "Message"), XS_Mob_Message, file, "$$$;@");
	newXSproto(strcpy(buf, "Message_StringID"), XS_Mob_Message_StringID, file, "$$$;$");
	newXSproto(strcpy(buf, "ModSkillDmgTaken"), XS_Mob_ModSkillDmgTaken, file, "$$$");
	newXSproto(strcpy(buf, "ModVulnerability"), XS_Mob_ModVulnerability, file, "$$$");
	newXSproto(strcpy(buf, "NPCSpecialAttacks"), XS_Mob_NPCSpecialAttacks, file, "$$$;$$");
	newXSproto(strcpy(buf, "NavigateTo"), XS_Mob_NavigateTo, file, "$$$$");
	newXSproto(strcpy(buf, "ProcessSpecialAbilities"), XS_Mob_ProcessSpecialAbilities, file, "$$");
	newXSproto(strcpy(buf, "ProjectileAnim"), XS_Mob_ProjectileAnim, file, "$$$;$$$$$$");
	newXSproto(strcpy(buf, "RandomizeFeatures"), XS_Mob_RandomizeFeatures, file, "$$;$");
	newXSproto(strcpy(buf, "RangedAttack"), XS_Mob_RangedAttack, file, "$$");
	newXSproto(strcpy(buf, "RemoveAllNimbusEffects"), XS_Mob_RemoveAllNimbusEffects, file, "$");
	newXSproto(strcpy(buf, "RemoveFromFeignMemory"), XS_Mob_RemoveFromFeignMemory, file, "$$");
	newXSproto(strcpy(buf, "RemoveNimbusEffect"), XS_Mob_RemoveNimbusEffect, file, "$$");
	newXSproto(strcpy(buf, "RemovePet"), XS_Mob_RemovePet, file, "$");
	newXSproto(strcpy(buf, "ResistSpell"), XS_Mob_ResistSpell, file, "$$$$");
	newXSproto(strcpy(buf, "RogueAssassinate"), XS_Mob_RogueAssassinate, file, "$$");
	newXSproto(strcpy(buf, "RunTo"), XS_Mob_RunTo, file, "$$$$");
	newXSproto(strcpy(buf, "Say"), XS_Mob_Say, file, "$$;@");
	newXSproto(strcpy(buf, "SeeHide"), XS_Mob_SeeHide, file, "$");
	newXSproto(strcpy(buf, "SeeImprovedHide"), XS_Mob_SeeImprovedHide, file, "$");
	newXSproto(strcpy(buf, "SeeInvisible"), XS_Mob_SeeInvisible, file, "$");
	newXSproto(strcpy(buf, "SeeInvisibleUndead"), XS_Mob_SeeInvisibleUndead, file, "$");
	newXSproto(strcpy(buf, "SendAppearanceEffect"), XS_Mob_SendAppearanceEffect, file, "$$;$$$$");
	newXSproto(strcpy(buf, "SendIllusion"), XS_Mob_SendIllusion, file, "$$;$$$$$$$$$$$$");
	newXSproto(strcpy(buf, "SendTo"), XS_Mob_SendTo, file, "$$$$");
	newXSproto(strcpy(buf, "SendToFixZ"), XS_Mob_SendToFixZ, file, "$$$$");
	newXSproto(strcpy(buf, "SendWearChange"), XS_Mob_SendWearChange, file, "$$");
	newXSproto(strcpy(buf, "SetAA"), XS_Mob_SetAA, file, "$$$;$");
	newXSproto(strcpy(buf, "SetAllowBeneficial"), XS_Mob_SetAllowBeneficial, file, "$$");
	newXSproto(strcpy(buf, "SetAppearance"), XS_Mob_SetAppearance, file, "$$;$");
	newXSproto(strcpy(buf, "SetBodyType"), XS_Mob_SetBodyType, file, "$$;$");
	newXSproto(strcpy(buf, "SetBucket"), XS_Mob_SetBucket, file, "$$$;$");
	newXSproto(strcpy(buf, "SetCurrentWP"), XS_Mob_SetCurrentWP, file, "$$");
	newXSproto(strcpy(buf, "SetDeltas"), XS_Mob_SetDeltas, file, "$$$$$");
	newXSproto(strcpy(buf, "SetDisableMelee"), XS_Mob_SetDisableMelee, file, "$$");
	newXSproto(strcpy(buf, "SetEntityVariable"), XS_Mob_SetEntityVariable, file, "$$$");
	newXSproto(strcpy(buf, "SetExtraHaste"), XS_Mob_SetExtraHaste, file, "$$");
	newXSproto(strcpy(buf, "SetFlurryChance"), XS_Mob_SetFlurryChance, file, "$$");
	newXSproto(strcpy(buf, "SetFlyMode"), XS_Mob_SetFlyMode, file, "$$");
	newXSproto(strcpy(buf, "SetFollowID"), XS_Mob_SetFollowID, file, "$$");
	newXSproto(strcpy(buf, "SetGender"), XS_Mob_SetGender, file, "$$");
	newXSproto(strcpy(buf, "SetGlobal"), XS_Mob_SetGlobal, file, "$$$$$;$");
	newXSproto(strcpy(buf, "SetHP"), XS_Mob_SetHP, file, "$$");
	newXSproto(strcpy(buf, "SetHate"), XS_Mob_SetHate, file, "$$;$$");
	newXSproto(strcpy(buf, "SetHeading"), XS_Mob_SetHeading, file, "$$");
	newXSproto(strcpy(buf, "SetInvisible"), XS_Mob_SetInvisible, file, "$$");
	newXSproto(strcpy(buf, "SetInvul"), XS_Mob_SetInvul, file, "$$");
	newXSproto(strcpy(buf, "SetLD"), XS_Mob_SetLD, file, "$$");
	newXSproto(strcpy(buf, "SetLevel"), XS_Mob_SetLevel, file, "$$;$");
	newXSproto(strcpy(buf, "SetMana"), XS_Mob_SetMana, file, "$$");
	newXSproto(strcpy(buf, "SetMaxHP"), XS_Mob_SetMaxHP, file, "$");
	newXSproto(strcpy(buf, "SetOOCRegen"), XS_Mob_SetOOCRegen, file, "$$");
	newXSproto(strcpy(buf, "SetOwnerID"), XS_Mob_SetOwnerID, file, "$$");
	newXSproto(strcpy(buf, "SetPet"), XS_Mob_SetPet, file, "$$");
	newXSproto(strcpy(buf, "SetPetID"), XS_Mob_SetPetID, file, "$$");
	newXSproto(strcpy(buf, "SetPetOrder"), XS_Mob_SetPetOrder, file, "$$");
	newXSproto(strcpy(buf, "SetRace"), XS_Mob_SetRace, file, "$$");
	newXSproto(strcpy(buf, "SetRunAnimSpeed"), XS_Mob_SetRunAnimSpeed, file, "$$");
	newXSproto(strcpy(buf, "SetRunning"), XS_Mob_SetRunning, file, "$$");
	newXSproto(strcpy(buf, "SetSlotTint"), XS_Mob_SetSlotTint, file, "$$$$$");
	newXSproto(strcpy(buf, "SetSpecialAbility"), XS_Mob_SetSpecialAbility, file, "$$$");
	newXSproto(strcpy(buf, "SetSpecialAbilityParam"), XS_Mob_SetSpecialAbilityParam, file, "$$$$");
	newXSproto(strcpy(buf, "SetTarget"), XS_Mob_SetTarget, file, "$$");
	newXSproto(strcpy(buf, "SetTargetable"), XS_Mob_SetTargetable, file, "$$");
	newXSproto(strcpy(buf, "SetTexture"), XS_Mob_SetTexture, file, "$$");
	newXSproto(strcpy(buf, "ShieldAbility"), XS_Mob_ShieldAbility, file, "$$$$$$$$");
	newXSproto(strcpy(buf, "Shout"), XS_Mob_Shout, file, "$$;@");
	newXSproto(strcpy(buf, "SignalClient"), XS_Mob_SignalClient, file, "$$$");
	newXSproto(strcpy(buf, "SpellEffect"), XS_Mob_SpellEffect, file, "$$;$$$$$$$$");
	newXSproto(strcpy(buf, "SpellFinished"), XS_Mob_SpellFinished, file, "$$;$$");
	newXSproto(strcpy(buf, "Spin"), XS_Mob_Spin, file, "$");
	newXSproto(strcpy(buf, "StartEnrage"), XS_Mob_StartEnrage, file, "$");
	newXSproto(strcpy(buf, "StopNavigation"), XS_Mob_StopNavigation, file, "$");
	newXSproto(strcpy(buf, "Stun"), XS_Mob_Stun, file, "$$");
	newXSproto(strcpy(buf, "TarGlobal"), XS_Mob_TarGlobal, file, "$$$$$$$");
	newXSproto(strcpy(buf, "TempName"), XS_Mob_TempName, file, "$:$");
	newXSproto(strcpy(buf, "ThrowingAttack"), XS_Mob_ThrowingAttack, file, "$$");
	newXSproto(strcpy(buf, "TryMoveAlong"), XS_Mob_TryMoveAlong, file, "$$$;$");
	newXSproto(strcpy(buf, "TypesTempPet"), XS_Mob_TypesTempPet, file, "$$;$$$$$");
	newXSproto(strcpy(buf, "WalkTo"), XS_Mob_WalkTo, file, "$$$$");
	newXSproto(strcpy(buf, "WearChange"), XS_Mob_WearChange, file, "$$$;$$");
	newXSproto(strcpy(buf, "WipeHateList"), XS_Mob_WipeHateList, file, "$");
	XSRETURN_YES;
}

#endif //EMBPERL_XS_CLASSES
