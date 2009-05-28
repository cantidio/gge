
Background* createYamattoBackground()
{
	Gorgon::SpritePack		*bgImg;
	bgImg= new Gorgon::SpritePack("tests/yamatto.gspk");
	Gorgon::AnimationPack	*bgAni;
	bgAni= new Gorgon::AnimationPack();
	
	for(int i=0; i<bgImg->getSize(); ++i)
	{
		Gorgon::Animation	*animation;
		animation= new Gorgon::Animation((*bgImg)[i].getGroup(),0,true);
		animation->add(0,new Gorgon::Frame((*bgImg)[i].getGroup(),(*bgImg)[i].getIndex(),-1));
		bgAni->add(animation);
	}
	//bgAni->save("tests/yamatto.gapk");
	
		Tile* tile= new Tile(*bgImg,*bgAni,0);
			tile->add(0,160);
			tile->add(160,	160);
			tile->add(192,	128);
			tile->add(240,	128);
			tile->add(352,	128);
			tile->add(384,	160);
			tile->add(416,	112);
			tile->add(448,	112);
			tile->add(480,	144);
			tile->add(512,	144);
			tile->add(544,	144);
			tile->add(704,	192);
			tile->add(736,	0);
			tile->add(512,	0);

		Tile* tile1= new Tile(*bgImg,*bgAni,1);
			tile1->add(208,	128);
			tile1->add(256,	128);

		Tile* tile2= new Tile(*bgImg,*bgAni,2);
			tile2->add(16,	160);
			tile2->add(176,	160);
			tile2->add(224,	128);
			tile2->add(272,	128);
			tile2->add(368,	128);
			tile2->add(400,	160);
			tile2->add(432,	112);
			tile2->add(464,	112);
			tile2->add(496,	144);
			tile2->add(528,	144);
			tile2->add(560,	144);
			tile2->add(720,	192);
			tile2->add(752,	0);
			tile2->add(528,	0);

		Tile* tile3= new Tile(*bgImg,*bgAni,3);
			tile3->add(32,	160);
			tile3->add(48,	160);
			tile3->add(64,	160);
			tile3->add(80,	160);
			tile3->add(96,	160);
			tile3->add(112,	160);
			tile3->add(128,	160);
			tile3->add(144,	160);
			tile3->add(288,	128);
			tile3->add(304,	128);
			tile3->add(320,	128);
			tile3->add(336,	128);
			tile3->add(304,	80);
			tile3->add(320,	80);
			tile3->add(336,	80);
			tile3->add(352,	80);
			tile3->add(416,	160);
			tile3->add(432,	160);
			tile3->add(448,	160);
			tile3->add(464,	160);
			tile3->add(624,	112);
			tile3->add(640,	112);

		Tile* tile4= new Tile(*bgImg,*bgAni,4);
			tile4->add(272,	32);
			tile4->add(288,	32);
			tile4->add(304,	32);
			tile4->add(320,	32);
			tile4->add(336,	32);
			tile4->add(352,	32);
			tile4->add(368,	32);
			tile4->add(384,	32);
			tile4->add(400,	32);
			tile4->add(416,	32);
			tile4->add(432,	32);
			tile4->add(448,	64);
			tile4->add(464,	64);
			tile4->add(480,	64);
			tile4->add(496,	64);
			tile4->add(512,	64);
			tile4->add(528,	64);
			tile4->add(560,	32);
			tile4->add(576,	32);
			tile4->add(592,	32);
			tile4->add(624,	32);
			tile4->add(640,	32);
			tile4->add(656,	32);
			tile4->add(688,	32);
			tile4->add(704,	32);
			tile4->add(304,	96);
			tile4->add(320,	96);
			tile4->add(336,	96);
			tile4->add(368,	96);
			tile4->add(624,	128);
			tile4->add(640,	128);
			tile4->add(656,	128);

		Tile* tile5= new Tile(*bgImg,*bgAni,5);
			tile5->add(288,	96);
			tile5->add(352,	96);
			tile5->add(544,	32);
			tile5->add(608,	32);
			tile5->add(672,	32);
			tile5->add(608,	128);

		Tile* tile6= new Tile(*bgImg,*bgAni,22);
			tile6->add(0,	176);
			tile6->add(160,	176);
			tile6->add(192,	144);
			tile6->add(240,	144);
			tile6->add(192,	208);
			tile6->add(240,	208);
			tile6->add(352,	144);
			tile6->add(352,	208);
			tile6->add(384,	176);
			tile6->add(448,	16);
			tile6->add(480,	16);
			tile6->add(512,	16);
			tile6->add(480,	160);
			tile6->add(512,	160);
			tile6->add(544,	160);
			tile6->add(480,	224);
			tile6->add(512,	224);
			tile6->add(544,	224);
			tile6->add(704,	208);
			tile6->add(736,	16);
			tile6->add(736,	80);

		Tile* tile7= new Tile(*bgImg,*bgAni,23);
			tile7->add(208,	144);
			tile7->add(256,	144);
			tile7->add(208,	208);
			tile7->add(256,	208);

		Tile* tile8= new Tile(*bgImg,*bgAni,24);
			tile8->add(16,	176);
			tile8->add(176,	176);
			tile8->add(224,	144);
			tile8->add(272,	144);
			tile8->add(224,	208);
			tile8->add(272,	208);
			tile8->add(368,	144);
			tile8->add(368,	208);
			tile8->add(400,	176);
			tile8->add(464,	16);
			tile8->add(496,	16);
			tile8->add(528,	16);
			tile8->add(496,	160);
			tile8->add(528,	160);
			tile8->add(560,	160);
			tile8->add(496,	224);
			tile8->add(528,	224);
			tile8->add(560,	224);
			tile8->add(720,	208);
			tile8->add(752,	16);
			tile8->add(752,	80);

		Tile* tile9= new Tile(*bgImg,*bgAni,25);
			tile9->add(32,	176);
			tile9->add(48,	176);
			tile9->add(64,	176);
			tile9->add(80,	176);
			tile9->add(96,	176);
			tile9->add(112,	176);
			tile9->add(128,	176);
			tile9->add(144,	176);
			tile9->add(288,	144);
			tile9->add(304,	144);
			tile9->add(320,	144);
			tile9->add(336,	144);
			tile9->add(416,	176);
			tile9->add(432,	176);
			tile9->add(448,	176);
			tile9->add(464,	176);

		Tile* tile10= new Tile(*bgImg,*bgAni,26);
			tile10->add(288,	64);
			tile10->add(352,	64);
			tile10->add(416,	64);
			tile10->add(416,	96);
			tile10->add(480,	96);
			tile10->add(480,	128);
			tile10->add(544,	64);
			tile10->add(544,	96);
			tile10->add(544,	128);
			tile10->add(608,	64);
			tile10->add(608,	96);
			tile10->add(672,	64);
			tile10->add(672,	96);
			tile10->add(672,	128);
			tile10->add(672,	160);
			tile10->add(608,	160);
			tile10->add(608,	192);
			tile10->add(672,	192);

		Tile* tile11= new Tile(*bgImg,*bgAni,27);
			tile11->add(576,	208);
			tile11->add(592,	208);
			tile11->add(608,	208);
			tile11->add(624,	208);
			tile11->add(640,	208);
			tile11->add(656,	208);
			tile11->add(672,	208);
			tile11->add(688,	208);

		Tile* tile12= new Tile(*bgImg,*bgAni,44);
			tile12->add(0,	208);
			tile12->add(160,	208);
			tile12->add(192,	176);
			tile12->add(240,	176);
			tile12->add(352,	176);
			tile12->add(384,	208);
			tile12->add(480,	192);
			tile12->add(512,	192);
			tile12->add(544,	192);
			tile12->add(736,	112);
			tile12->add(736,	48);

		Tile* tile13= new Tile(*bgImg,*bgAni,45);
			tile13->add(208,	176);
			tile13->add(256,	176);

		Tile* tile14= new Tile(*bgImg,*bgAni,46);
			tile14->add(16,	208);
			tile14->add(176,	208);
			tile14->add(224,	176);
			tile14->add(272,	176);
			tile14->add(368,	176);
			tile14->add(400,	208);
			tile14->add(496,	192);
			tile14->add(528,	192);
			tile14->add(560,	192);
			tile14->add(752,	112);
			tile14->add(752,	48);

		Tile* tile15= new Tile(*bgImg,*bgAni,47);
			tile15->add(32,	192);
			tile15->add(48,	192);
			tile15->add(64,	192);
			tile15->add(80,	192);
			tile15->add(96,	192);
			tile15->add(112,	192);
			tile15->add(128,	192);
			tile15->add(144,	192);
			tile15->add(32,	208);
			tile15->add(48,	208);
			tile15->add(64,	208);
			tile15->add(80,	208);
			tile15->add(96,	208);
			tile15->add(112,	208);
			tile15->add(128,	208);
			tile15->add(144,	208);
			tile15->add(32,	224);
			tile15->add(48,	224);
			tile15->add(64,	224);
			tile15->add(80,	224);
			tile15->add(96,	224);
			tile15->add(112,	224);
			tile15->add(128,	224);
			tile15->add(144,	224);
			tile15->add(288,	160);
			tile15->add(304,	160);
			tile15->add(320,	160);
			tile15->add(336,	160);
			tile15->add(288,	176);
			tile15->add(304,	176);
			tile15->add(320,	176);
			tile15->add(336,	176);
			tile15->add(288,	192);
			tile15->add(304,	192);
			tile15->add(320,	192);
			tile15->add(336,	192);
			tile15->add(288,	208);
			tile15->add(304,	208);
			tile15->add(320,	208);
			tile15->add(336,	208);
			tile15->add(288,	224);
			tile15->add(304,	224);
			tile15->add(320,	224);
			tile15->add(336,	224);
			tile15->add(416,	192);
			tile15->add(432,	192);
			tile15->add(448,	192);
			tile15->add(464,	192);
			tile15->add(416,	208);
			tile15->add(432,	208);
			tile15->add(448,	208);
			tile15->add(464,	208);
			tile15->add(416,	224);
			tile15->add(432,	224);
			tile15->add(448,	224);
			tile15->add(464,	224);

		Tile* tile16= new Tile(*bgImg,*bgAni,48);
			tile16->add(288,	48);
			tile16->add(352,	48);
			tile16->add(416,	48);
			tile16->add(544,	48);
			tile16->add(608,	48);
			tile16->add(672,	48);
			tile16->add(416,	80);
			tile16->add(480,	80);
			tile16->add(544,	80);
			tile16->add(608,	80);
			tile16->add(672,	80);
			tile16->add(288,	112);
			tile16->add(352,	112);
			tile16->add(480,	112);
			tile16->add(544,	112);
			tile16->add(672,	112);
			tile16->add(608,	144);
			tile16->add(672,	144);
			tile16->add(608,	176);
			tile16->add(672,	176);

		Tile* tile17= new Tile(*bgImg,*bgAni,49);
			tile17->add(576,	224);
			tile17->add(592,	224);
			tile17->add(608,	224);
			tile17->add(624,	224);
			tile17->add(640,	224);
			tile17->add(656,	224);
			tile17->add(672,	224);
			tile17->add(688,	224);

		Tile* tile18= new Tile(*bgImg,*bgAni,50);
			tile18->add(560,	64);
			tile18->add(624,	64);

		Tile* tile19= new Tile(*bgImg,*bgAni,51);
			tile19->add(576,	64);
			tile19->add(640,	64);

		Tile* tile20= new Tile(*bgImg,*bgAni,52);
			tile20->add(592,	64);
			tile20->add(656,	64);

		Tile* tile21= new Tile(*bgImg,*bgAni,12);
			tile21->add(544,	0);
			tile21->add(560,	0);
			tile21->add(576,	0);
			tile21->add(592,	0);
			tile21->add(608,	0);
			tile21->add(624,	0);
			tile21->add(640,	0);
			tile21->add(656,	0);

		Tile* tile22= new Tile(*bgImg,*bgAni,66);
			tile22->add(0,	192);
			tile22->add(160,	192);
			tile22->add(192,	192);
			tile22->add(240,	192);
			tile22->add(352,	192);
			tile22->add(384,	192);
			tile22->add(0,	224);
			tile22->add(160,	224);
			tile22->add(192,	224);
			tile22->add(240,	224);
			tile22->add(352,	224);
			tile22->add(384,	224);
			tile22->add(704,	224);
			tile22->add(480,	208);
			tile22->add(512,	208);
			tile22->add(544,	208);
			tile22->add(192,	160);
			tile22->add(240,	160);
			tile22->add(352,	160);
			tile22->add(480,	176);
			tile22->add(512,	176);
			tile22->add(544,	176);
			tile22->add(256,	0);
			tile22->add(304,	0);
			tile22->add(352,	0);
			tile22->add(400,	0);
			tile22->add(448,	0);
			tile22->add(480,	0);
			tile22->add(672,	0);
			tile22->add(448,	32);
			tile22->add(480,	32);
			tile22->add(512,	32);
			tile22->add(736,	32);
			tile22->add(736,	64);
			tile22->add(736,	96);
			tile22->add(736,	128);
			tile22->add(416,	128);
			tile22->add(448,	128);

		Tile* tile23= new Tile(*bgImg,*bgAni,67);
			tile23->add(208,	192);
			tile23->add(256,	192);
			tile23->add(208,	224);
			tile23->add(256,	224);
			tile23->add(208,	160);
			tile23->add(256,	160);
			tile23->add(272,	0);
			tile23->add(320,	0);
			tile23->add(368,	0);
			tile23->add(416,	0);
			tile23->add(688,	0);

		Tile* tile24= new Tile(*bgImg,*bgAni,68);
			tile24->add(16,	192);
			tile24->add(176,	192);
			tile24->add(224,	192);
			tile24->add(272,	192);
			tile24->add(368,	192);
			tile24->add(400,	192);
			tile24->add(16,	224);
			tile24->add(176,	224);
			tile24->add(224,	224);
			tile24->add(272,	224);
			tile24->add(368,	224);
			tile24->add(400,	224);
			tile24->add(720,	224);
			tile24->add(496,	208);
			tile24->add(528,	208);
			tile24->add(560,	208);
			tile24->add(224,	160);
			tile24->add(272,	160);
			tile24->add(368,	160);
			tile24->add(496,	176);
			tile24->add(528,	176);
			tile24->add(560,	176);
			tile24->add(288,	0);
			tile24->add(336,	0);
			tile24->add(384,	0);
			tile24->add(432,	0);
			tile24->add(464,	0);
			tile24->add(496,	0);
			tile24->add(704,	0);
			tile24->add(464,	32);
			tile24->add(496,	32);
			tile24->add(528,	32);
			tile24->add(752,	32);
			tile24->add(752,	64);
			tile24->add(752,	96);
			tile24->add(752,	128);
			tile24->add(432,	128);
			tile24->add(464,	128);

		Tile* tile25= new Tile(*bgImg,*bgAni,71);
			tile25->add(720,	0);
			tile25->add(720,	16);
			tile25->add(720,	32);
			tile25->add(720,	48);
			tile25->add(720,	64);
			tile25->add(720,	80);
			tile25->add(720,	96);
			tile25->add(720,	112);
			tile25->add(720,	128);
			tile25->add(720,	144);

		Tile* tile26= new Tile(*bgImg,*bgAni,72);
			tile26->add(560,	80);
			tile26->add(624,	80);

		Tile* tile27= new Tile(*bgImg,*bgAni,73);
			tile27->add(576,	80);
			tile27->add(640,	80);

		Tile* tile28= new Tile(*bgImg,*bgAni,74);
			tile28->add(592,	80);
			tile28->add(656,	80);

		Tile* tile29= new Tile(*bgImg,*bgAni,88);
			tile29->add(256,	16);
			tile29->add(304,	16);
			tile29->add(352,	16);
			tile29->add(400,	16);
			tile29->add(672,	16);
			tile29->add(448,	48);
			tile29->add(480,	48);
			tile29->add(512,	48);
			tile29->add(416,	144);
			tile29->add(448,	144);
			tile29->add(736,	144);

		Tile* tile30= new Tile(*bgImg,*bgAni,89);
			tile30->add(272,	16);
			tile30->add(320,	16);
			tile30->add(368,	16);
			tile30->add(416,	16);
			tile30->add(688,	16);

		Tile* tile31= new Tile(*bgImg,*bgAni,90);
			tile31->add(288,	16);
			tile31->add(336,	16);
			tile31->add(384,	16);
			tile31->add(432,	16);
			tile31->add(704,	16);
			tile31->add(464,	48);
			tile31->add(496,	48);
			tile31->add(528,	48);
			tile31->add(432,	144);
			tile31->add(464,	144);
			tile31->add(752,	144);

		Tile* tile32= new Tile(*bgImg,*bgAni,95);
			tile32->add(736,	160);

		Tile* tile33= new Tile(*bgImg,*bgAni,96);
			tile33->add(752,	160);

		Tile* tile34= new Tile(*bgImg,*bgAni,97);
			tile34->add(736,	176);

		Tile* tile35= new Tile(*bgImg,*bgAni,98);
			tile35->add(752,	176);

		Tile* tile36= new Tile(*bgImg,*bgAni,102);
			tile36->add(608,	112);
			tile36->add(288,	80);

		Tile* tile37= new Tile(*bgImg,*bgAni,103);
			tile37->add(368,	80);
			tile37->add(656,	112);

		Tile* tile38= new Tile(*bgImg,*bgAni,104);
			tile38->add(544,	16);
			tile38->add(560,	16);
			tile38->add(576,	16);
			tile38->add(592,	16);
			tile38->add(608,	16);
			tile38->add(624,	16);
			tile38->add(640,	16);
			tile38->add(656,	16);
			tile38->add(736,	192);
			tile38->add(752,	192);

		Tile* tile39= new Tile(*bgImg,*bgAni,11);
			tile39->add(736,	224);
			tile39->add(752,	224);

		Tile* tile40= new Tile(*bgImg,*bgAni,33);
			tile40->add(736,	208);
			tile40->add(752,	208);


		Tile* fundo= new Tile(*bgImg,*bgAni,108);
			fundo->add(0,0);
			
		Layer* layer0= new Layer(1,1);
		layer0->addTile(fundo);

		Layer layer(1,1);
		layer.addTile(tile);
		layer.addTile(tile1);
		layer.addTile(tile2);
		layer.addTile(tile3);
		layer.addTile(tile4);
		layer.addTile(tile5);
		layer.addTile(tile6);
		layer.addTile(tile7);
		layer.addTile(tile8);
		layer.addTile(tile9);
		layer.addTile(tile10);
		layer.addTile(tile11);
		layer.addTile(tile12);
		layer.addTile(tile13);
		layer.addTile(tile14);
		layer.addTile(tile15);
		layer.addTile(tile16);
		layer.addTile(tile17);
		layer.addTile(tile18);
		layer.addTile(tile19);
		layer.addTile(tile20);
		layer.addTile(tile21);
		layer.addTile(tile22);
		layer.addTile(tile23);
		layer.addTile(tile24);
		layer.addTile(tile25);
		layer.addTile(tile26);
		layer.addTile(tile27);
		layer.addTile(tile28);
		layer.addTile(tile29);
		layer.addTile(tile30);
		layer.addTile(tile31);
		layer.addTile(tile32);
		layer.addTile(tile33);
		layer.addTile(tile34);
		layer.addTile(tile35);
		layer.addTile(tile36);
		layer.addTile(tile37);
		layer.addTile(tile38);
		layer.addTile(tile39);
		layer.addTile(tile40);

	Background *bg;
	bg= new Background(768,240);
	//bg->addLayer(layer0);
	//bg->addLayer(layer);
	Layer as("teste_layer1.lua");
	bg->addLayer(new Layer("teste_layer1.lua"));
	return bg;
}