#define _LocalPlayer	0x4CCCE8
#define _TargetPlayer	0x4CCCC8
#define _guilds			0x645920
#define _SafeSpot		0x5E596C

typedef char CHAR;
typedef unsigned char BYTE;
typedef short SHORT;
typedef unsigned short WORD;
typedef int INT;
typedef unsigned int DWORD;
typedef float FLOAT;
typedef double DOUBLE;
typedef char* PCHAR;
typedef unsigned char* PBYTE;
typedef unsigned short* PWORD;
typedef unsigned int* PDWORD;
typedef void* PVOID;
typedef long LONG;
typedef unsigned long ULONG;

typedef struct _SPAWNINFO {
	BYTE Unknown0000;			// Always 3
	CHAR Name[30];
	BYTE Unknown0031[37];
	DWORD Zone;
	FLOAT Y;					// 0x48
	FLOAT X;					// 0x4C
	FLOAT Z;					// 0x50
	FLOAT Heading;				// 0x54
	FLOAT Unknown0088;
	FLOAT SpeedRun;				// 0x5C
	FLOAT SpeedY;
	FLOAT SpeedX;
	FLOAT SpeedZ;
	FLOAT SpeedHeading;
	FLOAT Unknown0112;
	FLOAT CameraAngle;			// 128=up -128=down
	DWORD pPrev;				// struct _SPAWNINFO *pPrev;
	DWORD pNext;				// struct _SPAWNINFO *pNext;
	DWORD pUnknown0128;			// 0x80 PVOID pUnknown0108;
	DWORD pActorInfo;			// PACTORINFO pActorInfo;
	DWORD pCharInfo;			// PCHARINFO pCharInfo;
	FLOAT CameraHeightOffset;
	FLOAT ModelHeightOffset;	// 0x90
	WORD SpawnID;				// 0x94
	WORD MasterID;				// 0x96
	DWORD HPMax;				// 0x98
	DWORD HPCurrent;			// 0x9C
	SHORT GuildID;				// 0xA0
	BYTE Unknown0162[6];
	BYTE Type;					// 0xA8
	BYTE Class;					// 0xA9
	WORD Race;					// 0xAA
	BYTE Gender;				// 0xAC
	BYTE Level;					// 0xAD
	BYTE Unknown0174[3];
	BYTE StandState;			// 0xB1
	BYTE Unknown0178[98];
	DWORD Anon;					// 0x114
	BYTE Unknown0280[4];
	BYTE AFK;					// 0x11C
	BYTE Unknown0285[7];
	WORD AARank;				// 0x124
	BYTE Unknown0294[6];
	CHAR Lastname[22];			// 0x12C
	BYTE Unknown0322[12];
	WORD Deity;					// 0x14E
} SPAWNINFO, *PSPAWNINFO;

PCHAR szGender[] = {
	"Male",
	"Female",
	"Neuter",
	"Unknown"
};

PCHAR szDeity[] = {
	"Bertoxxulous",   // 201
	"Brell Serilis",  // 202
	"Cazic-Thule",    // 203
	"Erollisi Marr",  // 204
	"Bristlebane",    // 205
	"Innoruuk",       // 206
	"Karana",         // 207
	"Mithaniel Marr", // 208
	"Prexus",         // 209
	"Quellious",      // 210
	"Rallos Zek",     // 211
	"Rodcet Nife",    // 212
	"Solusek Ro",     // 213
	"The Tribunal",   // 214
	"Tunare",         // 215
	"Veeshan",        // 216
};

PCHAR szClass[33] = {
	"Class 0",					// 0
	"Warrior",					// 1
	"Cleric",					// 2
	"Paladin",					// 3
	"Ranger",					// 4
	"Shadow Knight",			// 5
	"Druid",					// 6
	"Monk",						// 7 
	"Bard",						// 8
	"Rogue",					// 9
	"Shaman",					// 10
	"Necromancer",				// 11
	"Wizard",					// 12
	"Magician",					// 13
	"Enchanter",				// 14
	"Beastlord",				// 15
	"Banker",					// 16
	"Warrior Trainer",			// 17
	"Cleric Trainer",			// 18
	"Paladin Trainer",			// 19
	"Ranger Trainer",			// 20
	"Shadow Knight Trainer",	// 21
	"Druid Trainer",			// 22
	"Monk Trainer",				// 23
	"Bard Trainer",				// 24
	"Rogue Trainer",			// 25
	"Shaman Trainer",			// 26
	"Necromancer Trainer",		// 27
	"Wizard Trainer",			// 28
	"Magician Trainer",			// 29
	"Enchanter Trainer",		// 30
	"Beastlord Trainer",		// 31
	"Merchant"					// 32
};

PCHAR szRace[357] = {
	"Soldier",				// 0
	"Human",				// 1
	"Barbarian",			// 2
	"Erudite",				// 3
	"Wood Elf",				// 4
	"High Elf",				// 5
	"Dark Elf",				// 6
	"Half Elf",				// 7
	"Dwarf",				// 8
	"Troll",				// 9
	"Ogre",					// 10
	"Halfling",				// 11
	"Gnome",				// 12
	"Aviak",				// 13
	"Werewolf",				// 14
	"Brownie",				// 15
	"Centaur",				// 16
	"Golem",				// 17
	"Giant/Cyclops",		// 18
	"Poison Dragon",		// 19
	"Doppleganger",			// 20
	"Evil Eye",				// 21
	"Beetle",				// 22
	"Kerran",				// 23
	"Fish",					// 24
	"Fairy",				// 25
	"Froglok",				// 26
	"Froglok Ghoul",		// 27
	"Fungusman",			// 28
	"Gargoyle",				// 29
	"Gasbag",				// 30
	"Gelatinous Cube",		// 31
	"Ghost",				// 32
	"Ghoul",				// 33
	"Bat",					// 34
	"Eel",					// 35
	"Rat",					// 36
	"Snake",				// 37
	"Spider",				// 38
	"Gnoll",				// 39
	"Goblin",				// 40
	"Gorilla",				// 41
	"Wolf",					// 42
	"Bear",					// 43
	"Freeport Citizen",		// 44
	"Demi Lich",			// 45
	"Imp",					// 46
	"Griffin",				// 47
	"Kobold",				// 48
	"Dragon",				// 49
	"Lion",					// 50
	"Lizardman",			// 51
	"Chest",				// 52
	"Minotaur",				// 53
	"Orc",					// 54
	"Human Beggar",			// 55
	"Pixie",				// 56
	"Dracnid",				// 57
	"Solusek Ro",			// 58
	"Bloodgill Goblin",		// 59
	"Skeleton",				// 60
	"Shark",				// 61
	"Tunare",				// 62
	"Tiger",				// 63
	"Treant",				// 64
	"Vampire",				// 65
	"Rallos Zek Avatar",	// 66
	"Highpass Citizen",		// 67
	"Tentacle",				// 68
	"Willowisp",			// 69
	"Zombie",				// 70
	"Qeynos Citizen",		// 71
	"Ship",					// 72
	"Ferry",				// 73
	"Piranha",				// 74
	"Elemental",			// 75
	"Puma",					// 76
	"Neriak Citizen",		// 77
	"Erudin Citizen",		// 78
	"Bixie",				// 79
	"Reanimated Hand",		// 80
	"Rivervale Citizen",	// 81
	"Scarecrow",			// 82
	"Skunk",				// 83
	"Snake Elemental",		// 84
	"Spectre",				// 85
	"Sphinx",				// 86
	"Armadillo",			// 87
	"Clockwork Gnome",		// 88
	"Drake",				// 89
	"Halas Citizen",		// 90
	"Alligator",			// 91
	"Grobb Citizen",		// 92
	"Oggok Citizen",		// 93
	"Kaladim Citizen",		// 94
	"Cazic Thule",			// 95
	"Cockatrice",			// 96
	"Daisy Man",			// 97
	"Elf Vampire",			// 98
	"Amygdalan",			// 99
	"Dervish",				// 100
	"Efreeti",				// 101
	"Froglok Tadpole",		// 102
	"Kedge",				// 103
	"Leech",				// 104
	"Swordfish",			// 105
	"Felwithe Citizen",		// 106
	"Mammoth",				// 107
	"Eye of Zomm",			// 108
	"Wasp",					// 109
	"Mermaid",				// 110
	"Harpie",				// 111
	"Kelethin Citizen",		// 112
	"Drixie",				// 113
	"Ghost Ship",			// 114
	"Clam",					// 115
	"Seahorse",				// 116
	"Dwarf Ghost",			// 117
	"Erudite Ghost",		// 118
	"Sabertooth Cat",		// 119
	"Spirit Wolf",			// 120
	"Gorgon",				// 121
	"Dragon Skeleton",		// 122
	"Innoruuk",				// 123
	"Unicorn",				// 124
	"Pegasus",				// 125
	"Djinn",				// 126
	"Invisible Man",		// 127
	"Iksar",				// 128
	"Scorpion",				// 129
	"Vah Shir",				// 130
	"Sarnak",				// 131
	"Draglock",				// 132
	"Drolvarg",				// 133
	"Mosquito",				// 134
	"Rhino",				// 135
	"Xalgoz",				// 136
	"Kunark Goblin",		// 137
	"Yeti",					// 138
	"Cabilis Citizen",		// 139
	"Forest Giant",			// 140
	"Boat",					// 141
	"Minor Illusion",		// 142
	"Tree Illusion",		// 143
	"Burynai",				// 144
	"Goo",					// 145
	"Sarnak Ghost",			// 146
	"Iksar Ghost",			// 147
	"Kunark Fish",			// 148
	"Scorpikis",			// 149
	"Erollisi",				// 150
	"Tribunal",				// 151
	"Bertoxxulous",			// 152
	"Bristlebane",			// 153
	"Fay Drake",			// 154
	"Sarnak Skeleton",		// 155
	"Ratman",				// 156
	"Wyvern",				// 157
	"Wurm",					// 158
	"Devourer",				// 159
	"Iksar Golem",			// 160
	"Iksar Skeleton",		// 161
	"Plant",				// 162
	"Raptor",				// 163
	"Sarnak Golem",			// 164
	"Water Dragon",			// 165
	"Iksar Hand",			// 166
	"Cactus",				// 167
	"Holgresh",				// 168
	"Brontotherium",		// 169
	"Snow Dervish",			// 170
	"Dire Wolf",			// 171
	"Manticore",			// 172
	"Totem",				// 173
	"Ice Spectre",			// 174
	"Enchanted Armor",		// 175
	"Bunny",				// 176
	"Walrus",				// 177
	"Geonid",				// 178
	"Race 179",				// 179
	"Race 180",				// 180
	"Yakkar",				// 181
	"Faun",					// 182
	"Coldain",				// 183
	"Velious Dragon",		// 184
	"Hag",					// 185
	"Hippogriff",			// 186
	"Siren",				// 187
	"Frost Giant",			// 188
	"Storm Giant",			// 189
	"Otterman",				// 190
	"Kodiak/Panda",			// 191
	"Clockwork Dragon",		// 192
	"Abhorent",				// 193
	"Sea Turtle",			// 194
	"White/Black Dragon",	// 195
	"Ghost Dragon",			// 196
	"Ronnie Test",			// 197
	"Prismatic Dragon",		// 198
	"Shik`nar",				// 199
	"Rockhopper",			// 200
	"Underbulk",			// 201
	"Grimling",				// 202
	"Worm",					// 203
	"Evan Test",			// 204
	"Kahli Shah",			// 205
	"Owlbear",				// 206
	"Rhino Beetle",			// 207
	"Vampyre",				// 208
	"Earth Elemental",		// 209
	"Air Elemental",		// 210
	"Water Elemental",		// 211
	"Fire Elemental",		// 212
	"Minnow",				// 213
	"Thought Horror",		// 214
	"Bogling",				// 215
	"Horse",				// 216
	"Shissar",				// 217
	"Fungal Fiend",			// 218
	"Vampire Volatalis",	// 219
	"Stonegrabber",			// 220
	"Scarlet Cheetah",		// 221
	"Zelniak",				// 222
	"Lightcrawler",			// 223
	"Shade",				// 224
	"Sunflower",			// 225
	"Tashakhi",				// 226
	"Mushroom",				// 227
	"Garanga",				// 228
	"Netherbian",			// 229
	"Akheva",				// 230
	"Spire Spirit",			// 231
	"Sonic Wolf",			// 232
	"Trap",					// 233
	"Vah Shir Skeleton",	// 234
	"Mutant",				// 235
	"Seru",					// 236
	"Recuso",				// 237
	"Vah Shir King",		// 238
	"Shar Vahl Citizens",	// 239
	"Scion",				// 240
	"Nightstalker",			// 241
	"Potameid",				// 242
	"Nymph",				// 243
	"Ent",					// 244
	"Wrinnfly",				// 245
	"Coirnav",				// 246
	"Solusek Ro",			// 247
	"Clockwork Golem",		// 248
	"Clockwork Brain",		// 249
	"Spectral Banshee",		// 250
	"Guard of Justice",		// 251
	"PoM Castle",			// 252
	"Disease Boss",			// 253
	"Solusek Ro Guard",		// 254
	"Bertoxxulous",			// 255
	"Tribunal",				// 256
	"Terris Thule",			// 257
	"Vegerog",				// 258
	"Crocodile",			// 259
	"Nightmare Bat",		// 260
	"Slarghilug",			// 261
	"Tranquilion",			// 262
	"Tin Soldier",			// 263
	"Nightmare Wraith",		// 264
	"Malarian",				// 265
	"Knight of Pestilence",	// 266
	"Lepertoloth",			// 267
	"Bubonian Boss",		// 268
	"Bubonian Underling",	// 269
	"Pusling",				// 270
	"Triloun",				// 271
	"Stormrider",			// 272
	"Junk Beast",			// 273
	"Broken Clockwork",		// 274
	"Giant Clockwork",		// 275
	"Clockwork Beetle",		// 276
	"Hobgoblin",			// 277
	"Storm Lord",			// 278
	"Blood Raven",			// 279
	"Nightmare Gargoyle",	// 280
	"Torment Construct",	// 281
	"Skeletal Horse",		// 282
	"Saryn",				// 283
	"Fennin Ro",			// 284
	"Kaniz",				// 285
	"Necromancer Priest",	// 286
	"Nightmare",			// 287
	"Rallos Zek",			// 288
	"Tallon Zek",			// 289
	"Vallon Zek",			// 290
	"Air Mephit",			// 291
	"Earth Mephit",			// 292
	"Fire Mephit",			// 293
	"Mephit",				// 294
	"Zebuxoruk",			// 295
	"Mithaniel Marr",		// 296
	"Nightmare Rider",		// 297
	"The Rathe",			// 298
	"Xegony",				// 299
	"Balrog",				// 300
	"Test",					// 301
	"Regrua",				// 302
	"Pheonix",				// 303
	"Tiamat",				// 304
	"Bear",					// 305
	"Earth Giant",			// 306
	"Water Giant",			// 307
	"Electric Giant",		// 308
	"Air Giant",			// 309
	"Wood Giant",			// 310
	"Fire Giant",			// 311
	"Sky Giant",			// 312
	"War Wraith",			// 313
	"Wrulon",				// 314
	"Squid",				// 315
	"Frog",					// 316
	"Flying Serpent",		// 317
	"Tactics Soldier",		// 318
	"Armored Boar",			// 319
	"Djinni",				// 320
	"Boar",					// 321
	"Knight of Marr",		// 322
	"Black Armor",			// 323
	"Nightmare Knight",		// 324
	"Rallos Ogre",			// 325
	"Arachnid",				// 326
	"Crystal Arachnid",		// 327
	"Tower Model",			// 328
	"Portal",				// 329
	"Race 330",				// 330
	"Race 331",				// 331
	"Race 332",				// 332
	"Race 333",				// 333
	"Race 334",				// 334
	"Race 335",				// 335
	"Race 336",				// 336
	"Race 337",				// 337
	"Race 338",				// 338
	"Race 339",				// 339
	"Race 340",				// 340
	"Race 341",				// 341
	"Race 342",				// 342
	"Race 343",				// 343
	"Race 344",				// 344
	"Race 345",				// 345
	"Race 346",				// 346
	"Race 347",				// 347
	"Race 348",				// 348
	"Race 349",				// 349
	"Race 350",				// 350
	"Race 351",				// 351
	"Race 352",				// 352
	"Race 353",				// 353
	"Race 354",				// 354
	"Race 355",				// 355
	"Scaled Wolf",			// 356
};

PCHAR szZone[224] = {
	"Zone 0",							// 0
	"South Qeynos",						// 1
	"North Qeynos",						// 2
	"Surefall Glade",					// 3
	"Qeynos Hills",						// 4
	"Highpass Hold",					// 5
	"HighKeep",							// 6
	"Zone 7",							// 7
	"North Freeport",					// 8
	"West Freeport",					// 9
	"East Freeport",					// 10
	"Clan RunnyEye",					// 11
	"West Karana",						// 12
	"North Karana",						// 13
	"South Karana",						// 14
	"East Karana",						// 15
	"Gorge of King Xorbb",				// 16
	"BlackBurrow",						// 17
	"Infected Paw",						// 18
	"Rivervale",						// 19
	"Kithicor Forest",					// 20
	"West Commonlands",					// 21
	"East Commonlands",					// 22
	"Erudin Palace",					// 23
	"Erudin",							// 24
	"Nektulos Forest",					// 25
	"Zone 26",							// 26
	"Lavastorm Mountains",				// 27
	"Zone 28",							// 28
	"Halas",							// 29
	"Everfrost Peaks",					// 30
	"Solusek's Eye",					// 31
	"Nagafen's Lair",					// 32
	"Misty Thicket",					// 33
	"North Ro",							// 34
	"South Ro",							// 35
	"Befallen",							// 36
	"Oasis of Marr",					// 37
	"Toxxulia Forest",					// 38
	"The Ruins of Old Paineel",			// 39
	"Neriak Foreign Quarter",			// 40
	"Neriak Commons",					// 41
	"Neriak Third Gate",				// 42
	"Zone 43",							// 43
	"Najena",							// 44
	"Qeynos Catacombs",					// 45
	"Innothule Swamp",					// 46
	"The Feerrott",						// 47
	"Cazic-Thule",						// 48
	"Oggok",							// 49
	"Mountains of Rathe",				// 50
	"Lake Rathetear",					// 51
	"Grobb",							// 52
	"Zone 53",							// 53
	"Greater Faydark",					// 54
	"Ak'Anon",							// 55
	"Steamfont Mountains",				// 56
	"Lesser Faydark",					// 57
	"Clan Crushbone",					// 58
	"Castle Mistmoore",					// 59
	"South Kaladim",					// 60
	"North Felwithe",					// 61
	"South Felwithe",					// 62
	"Estate of Unrest",					// 63
	"Kedge Keep",						// 64
	"Upper Guk",						// 65
	"Lower Guk",						// 66
	"North Kaladim",					// 67
	"Butcherblock Mountains",			// 68
	"Ocean of Tears",					// 69
	"Dagnor's Cauldron",				// 70
	"Plane of Sky",						// 71
	"Plane of Fear",					// 72
	"Permafrost Keep",					// 73
	"Kerra Isle",						// 74
	"Paineel",							// 75
	"Zone 76",							// 76
	"The Arena",						// 77
	"The Field of Bone",				// 78
	"Warsliks Wood",					// 79
	"Temple of Solusek Ro",				// 80
	"Temple of Droga",					// 81
	"West Cabilis",						// 82
	"Swamp of No Hope",					// 83
	"Firiona Vie",						// 84
	"Lake of Ill Omen",					// 85
	"Dreadlands",						// 86
	"Burning Woods",					// 87
	"Kaesora",							// 88
	"Old Sebilis",						// 89
	"City of Mist",						// 90
	"Skyfire Mountains",				// 91
	"Frontier Mountains",				// 92
	"The Overthere",					// 93
	"The Emerald Jungle",				// 94
	"Trakanon's Teeth",					// 95
	"Timorous Deep",					// 96
	"Kurn's Tower",						// 97
	"Erud's Crossing",					// 98
	"Zone 99",							// 99
	"Stonebrunt Mountains",				// 100
	"The Warrens",						// 101
	"Karnor's Castle",					// 102
	"Chardok",							// 103
	"Dalnir",							// 104
	"Howling Stones",					// 105
	"East Cabilis",						// 106
	"Mines of Nurga",					// 107
	"Veeshan's Peak",					// 108
	"Zone 109",							// 109
	"Iceclad Ocean",					// 110
	"Tower of Frozen Shadow",			// 111
	"Velketor's Labyrinth",				// 112
	"Kael Drakkal",						// 113
	"Skyshrine",						// 114
	"Thurgadin",						// 115
	"Eastern Wastes",					// 116
	"Cobalt Scar",						// 117
	"Great Divide",						// 118
	"The Wakening Land",				// 119
	"Western Wastes",					// 120
	"Crystal Caverns",					// 121
	"Zone 122",							// 122
	"Dragon Necropolis",				// 123
	"Temple of Veeshan",				// 124
	"Siren's Grotto",					// 125
	"Plane of Mischief",				// 126
	"Plane of Growth",					// 127
	"Sleeper's Tomb",					// 128
	"Icewell Keep",						// 129
	"Zone 130",							// 130
	"Zone 131",							// 131
	"Zone 132",							// 132
	"Zone 133",							// 133
	"Zone 134",							// 134
	"Zone 135",							// 135
	"Zone 136",							// 136
	"Zone 137",							// 137
	"Zone 138",							// 138
	"Zone 139",							// 139
	"Zone 140",							// 140
	"Zone 141",							// 141
	"Zone 142",							// 142
	"Zone 143",							// 143
	"Zone 144",							// 144
	"Zone 145",							// 145
	"Zone 146",							// 146
	"Zone 147",							// 147
	"Zone 148",							// 148
	"Zone 149",							// 149
	"Shadow Haven",						// 150
	"The Bazaar",						// 151
	"The Nexus",						// 152
	"Echo Caverns",						// 153
	"Acrylia Caverns",					// 154
	"Shar Vahl",						// 155
	"Paludal Caverns",					// 156
	"Fungus Grove",						// 157
	"Vex Thal",							// 158
	"Sanctus Seru",						// 159
	"Katta Castellum",					// 160
	"Netherbian Lair",					// 161
	"Ssraeshza Temple",					// 162
	"Grieg's End",						// 163
	"The Deep",							// 164
	"Shadeweaver's Thicket",			// 165
	"Hollowshade Moor",					// 166
	"Grimling Forest",					// 167
	"Marus Seru",						// 168
	"Mons Letalis",						// 169
	"The Twilight Sea",					// 170
	"The Grey",							// 171
	"The Tenebrous Mountains",			// 172
	"The Maiden's Eye",					// 173
	"Dawnshroud Peaks",					// 174
	"The Scarlet Desert",				// 175
	"The Umbral Plains",				// 176
	"Zone 177",							// 177
	"Zone 178",							// 178
	"Akheva Ruins",						// 179
	"Zone 180",							// 180
	"The Jaggedpine Forest",			// 181
	"Zone 182",							// 182
	"Zone 183",							// 183
	"Zone 184",							// 184
	"Zone 185",							// 185
	"Zone 186",							// 186
	"Zone 187",							// 187
	"Zone 188",							// 188
	"Zone 189",							// 189
	"Zone 190",							// 190
	"Zone 191",							// 191
	"Zone 192",							// 192
	"Zone 193",							// 193
	"Zone 194",							// 194
	"Zone 195",							// 195
	"Zone 196",							// 196
	"Zone 197",							// 197
	"Zone 198",							// 198
	"Zone 199",							// 199
	"Ruins of Lxanvom",					// 200
	"Plane of Justice",					// 201
	"Plane of Knowledge",				// 202
	"Plane of Tranquility",				// 203
	"Plane of Nightmare",				// 204
	"Plane of Disease",					// 205
	"Plane of Innovation",				// 206
	"Plane of Torment",					// 207
	"Plane of Valor",					// 208
	"Torden, The Bastion of Thunder",	// 209
	"Plane of Storms",					// 210
	"Halls of Honor",					// 211
	"Solusek Ro's Tower",				// 212
	"Zone 213",							// 213
	"Drunder, Fortress of Zek",			// 214
	"Eryslai, the Kingdom of Wind",		// 215
	"Reef of Coirnav",					// 216
	"Doomfire, The Burning Lands",		// 217
	"Vegarlson, The Earthen Badlands",	// 218
	"Plane of Time A",					// 219
	"Temple of Marr",					// 220
	"Lair of Terris Thule",				// 221
	"Stronghold of the Twelve",			// 222
	"Plane of Time B"					// 223
};