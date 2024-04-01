#r "../../bin/dotnet/DotNetTypes.dll"

using System;
using System.Collections;
using System.Runtime;
using System.Runtime.InteropServices;
using System.Diagnostics;

private int counter = 0;
public void Timer(NpcEvent e) {
   e.logSys.QuestDebug($"Timer hit 21 {counter++}");
   // e.npc.Say("Something");
}

public void TimerStart(NpcEvent e) {
    e.logSys.QuestDebug($"Timer start: e {e.data}");
    Console.WriteLine($"Timer start: e {e.data}");

}

public void Say(NpcEvent e)
{
    e.npc.Say($"Hi there 123, {e.mob.GetCleanName()}! Spend your time wisely in the city of Qeynos. Do not let your mind wander to thoughts of bravado or crime. My guards can easily put to rest any outbreaks. Good day to you, citizen!");
    //e.questManager.signal(1068);
    e.npc.AddToHateList(e.entityList.GetNPCByName("Ebon_Strongbear").CastToMob());
    e.npc.Attack(e.entityList.GetNPCByName("Ebon_Strongbear"));
    for (struct_HateList h in e.npc.GetHateList()) {
        e.logSys.QuestDebug($"On hate list: {h.entity_on_hatelist.GetName()}");
    }
    //e.npc.AddToHateList(e.mob);
   // e.npc.GetHateList().PrintHateListToClient(e.mob);
}

public void Spawn(NpcEvent e)
{
    Console.WriteLine("Zone bootup - spawn");
    e.questManager.settimerMS("tillin", 5000);

}

public void Signal(NpcEvent e)
{
    Console.WriteLine("Hit signal new 1");
    e.npc.Say("Ah.  Good.  You have arrived.  Executioner, could you please visit McNeal Jocub at Fish's Tavern.  He has violated our laws and the sentence is death.");
}

public void Trade(NpcEvent e)
{
    var client = e.mob.CastToClient();
    foreach (ItemInstance item in e.itemList)
    {
        if (item.GetID() == 13915)
        {
            e.npc.Say("Very good! One less gnoll the people of Qeynos need to fear. Here is your bounty as promised.");
            e.questManager.faction(219, 2, 0); // Antonius Bayle
            e.questManager.faction(223, -2, 0); // Circle of Unseen Hands
            e.questManager.faction(230, -2, 0); // Corrupt Qeynos Guards
            e.questManager.faction(262, 2, 0); // Guards of Qeynos
            e.questManager.faction(291, 2, 0); // Merchants of Qeynos
            e.questManager.summonitem(10070);
            e.questManager.ding();
            e.questManager.exp(7000);
        }
        else if (item.GetID() == 18815)
        {
            e.npc.Say("Wonder what the text should be here");
            e.questManager.faction(219, 1, 0); // Antonius Bayle
            e.questManager.faction(223, -1, 0); // Circle of Unseen Hands
            e.questManager.faction(230, -1, 0); // Corrupt Qeynos Guards
            e.questManager.faction(262, 1, 0); // Guards of Qeynos
            e.questManager.faction(291, 1, 0); // Merchants of Qeynos
            e.questManager.summonitem(13305);
            e.questManager.ding();
            e.questManager.exp(500);
            Random rnd = new Random();
            client.CashReward((uint)rnd.Next(1, 11), (uint)rnd.Next(1, 11), (uint)rnd.Next(1, 11), (uint)rnd.Next(1, 11));
            // e.questManager.spawn2(1202, 62, 0, new Vec4(-412, 75, -24, 0)); // NPC: Executioner
        }
        else if (item.GetID() == 18912)
        {
            e.npc.Say("So, an assassin has been sent to Qeynos! I shall have my guards keep an eye out for any suspicious looking visitors. As for you... you should speak with the Surefall Glade ambassador. Ambassador Gash is staying at the Lion's Mane Inn here in South Qeynos. Inform him that [an assassin has been sent to kill] him. Do not let the assassin near him!");
            e.questManager.faction(219, 1, 0); // Antonius Bayle
            e.questManager.faction(223, -1, 0); // Circle of Unseen Hands
            e.questManager.faction(230, -1, 0); // Corrupt Qeynos Guards
            e.questManager.faction(262, 1, 0); // Guards of Qeynos
            e.questManager.faction(291, 1, 0); // Merchants of Qeynos
            e.questManager.summonitem(10070);
            e.questManager.ding();
            e.questManager.exp(500);
            Random rnd = new Random();
            client.CashReward((uint)rnd.Next(1, 11), (uint)rnd.Next(1, 11), (uint)rnd.Next(1, 11), (uint)rnd.Next(1, 11));
        }
    }
}