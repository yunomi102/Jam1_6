//ディレクター:茂木恵大
//サブディレクター:柏木春人
#include"setting.h"

void init(void);
void titleupdate();
void tutorialupdate();
void update(void);
void draw(void);

enum gamescene
{
	restart,
	title,
	tutorial,
	game
};
gamescene scene;
bool pushenter;
bool tutorialflag;
bool gameclearbgm;
bool gameoverbgm;
int titleback;
int titlelogo;
int tutoriallogo;
int gameclearlogo;
int gameoverlogo;
int tutoriallogo1;
int tutoriallogo2;
int tutoriallogo3;
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	init();

	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (scene == restart)
		{
			init();
			tutorialflag = false;
		}
		if (scene == title)
		{
			DrawExtendGraph(0, 0, 800, 600, titleback, true);
			titleupdate();
		}
		if (scene == tutorial)
		{
			DrawExtendGraph(0, 0, 800, 600, titleback, true);
			tutorialupdate();
		}
		if (scene == game)
		{
			update();
			if (gameclearflag == true)
			{
				DrawExtendGraph(0, 200, 800, 400, gameclearlogo, true);
				DrawFormatString(250, 450, GetColor(255, 255, 255), "SCORE:%d", score);
				if (gameclearbgm == false)
				{
					PlayMusic("gameclearbgm.mp3", DX_PLAYTYPE_LOOP);
					gameclearbgm = true;
				}
			}
			if (gameclearflag == false && gameoverflag == true)
			{
				DrawExtendGraph(0, 200, 800, 400, gameoverlogo, true);
				DrawString(550, 500, "RESTART TO PUSH ENTER KEY", GetColor(255, 255, 255));
				SetFontSize(35);
				DrawFormatString(250,450,GetColor(255,255,255),"SCORE:%d",score);
				SetFontSize(16);
				if (gameoverbgm == false)
				{
					PlayMusic("gameoverbgm.mp3", DX_PLAYTYPE_LOOP);
					gameoverbgm = true;
				}
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
				{
					pushenter = true;
					scene = restart;
				}
				if (CheckHitKey(KEY_INPUT_RETURN) == 0)
				{
					pushenter = false;
				}
			}
		}
		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}
	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
void init(void)
{
	initsetting();
	initplayer();
	initplayershot();
	initenemy();
	initenemyshot();
	initstage();
	initgame();
	initishit();
	initEffect();
	tutorialflag = true;
	gameclearbgm = false;
	gameoverbgm = false;
	titleback = LoadGraph("titleback.png");
	titlelogo = LoadGraph("titlelogo.png");
	tutoriallogo = LoadGraph("tutoriallogo.png");
	tutoriallogo1 = LoadGraph("tutoriallogo1.png");
	tutoriallogo2 = LoadGraph("tutoriallogo2.png");
	tutoriallogo3 = LoadGraph("tutoriallogo3.png");
	gameclearlogo = LoadGraph("gameclearlogo.png");
	gameoverlogo = LoadGraph("gameoverlogo.png");
	PlayMusic("startbgm.mp3", DX_PLAYTYPE_LOOP);
	scene = title;
}
void update(void)
{
	updatesetting();
	updatestage();
	updateplayershot();
	updateplayer();
	updateenemyshot();
	updateenemy();
	updategame();
	updatechangestage();
	updateishit();
	updateEffect();
	draw();
}
void draw(void)
{
	drawstage();
	drawplayershot();
	drawenemyshot();
	drawplayer();
	drawenemy();
	drawgame();
	drawEffect();
	drawchangestage();
}
void titleupdate(void)
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
	{
		pushenter = true;
		PlayMusic("tutorialbgm.mp3", DX_PLAYTYPE_LOOP);
		scene = tutorial;
	}
	DrawExtendGraph(0, 250, 800, 350, titlelogo, true);
	DrawString(650, 500, "PUSH ENTER KEY", GetColor(255, 255, 255));
	if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		pushenter = false;
	}
}
void tutorialupdate(void)
{
	if (tutorialflag == true)
	{
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
		{
			pushenter = true;
			scene = game;
			PlayMusic("gamebgm.mp3", DX_PLAYTYPE_LOOP);
		}
	}
	else if (tutorialflag == false)
	{
		scene = game;
		PlayMusic("gamebgm.mp3", DX_PLAYTYPE_LOOP);
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		pushenter = false;
	}
	DrawExtendGraph(100, 100, 700, 250, tutoriallogo, true);
	DrawExtendGraph(200, 250, 600, 380, tutoriallogo1, true);
	DrawExtendGraph(200, 350, 600, 480, tutoriallogo2, true);
	DrawExtendGraph(200, 450, 600, 580, tutoriallogo3, true);
	
	SetFontSize(16);
	DrawString(650, 500, "PUSH ENTER KEY", GetColor(255, 255, 255));
}