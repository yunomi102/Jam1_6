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
int titlelogo;
int tutoriallogo;
int gameclearlogo;
int gameoverlogo;

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
		}
		if (scene == title)
		{
			titleupdate();
		}
		if (scene == tutorial)
		{
			tutorialupdate();
		}
		if (scene == game)
		{
			update();
			if (gameclearflag == true)
			{
				DrawExtendGraph(0, 200, 800, 400, gameclearlogo, true);
			}
			if (gameclearflag == false && gameoverflag == true)
			{
				DrawExtendGraph(0, 200, 800, 400, gameoverlogo, true);
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && pushenter == false)
				{
					tutorialflag = true;
					scene = restart;
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
	tutorialflag = true;
	titlelogo = LoadGraph("titlelogo.png");
	tutoriallogo = LoadGraph("tutoriallogo.png");
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

	draw();
}
void draw(void)
{
	drawstage();
	drawplayershot();
	drawplayer();
	drawenemyshot();
	drawenemy();
	drawgame();
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
	DrawExtendGraph(0, 200, 800, 400, titlelogo, true);
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
		pushenter = false;
		scene == game;
		PlayMusic("gamebgm.mp3", DX_PLAYTYPE_LOOP);
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		pushenter = false;
	}
	DrawExtendGraph(0, 200, 800, 400, tutoriallogo, true);
}