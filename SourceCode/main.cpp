
#include "all.h"

//------< 変数 >----------------------------------------------------------------
int curScene    = SCENE_NONE;
int nextScene   = SCENE_TITLE;
int outScrene0 = SCENE_RESULT;

Sprite* result;
Sprite* tutorial;

int tutorial1 = SCENE_TUTORIAL1;
//--------------------------------------
//  WinMain（エントリポイント）
//--------------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    GameLib::init(L"ゲームプログラミング�T", SCREEN_W, SCREEN_H);

    // オーディオの初期設定
    audio_init();

    while (GameLib::gameLoop())
    {
        // シーン切り替え処理
        if (curScene != nextScene)
        {
            // 現在のシーンに応じた終了処理
            switch (curScene)
            {
            case SCENE_TITLE:
                title_deinit();
                break;

            case SCENE_GAME:
                game_deinit();
                break;
            case SCENE_GAME2:
                game2_deinit();
                break;

            case SCENE_RESULT:
                result_deinit();
                break;

            case SCENE_TUTORIAL1:
                tutorial_deinit();
                break;

            case SCENE_SELECT:
                select_deinit();
                break;
            }

            // 次のシーンに応じた初期設定処理
            switch (nextScene)
            {
            case SCENE_TITLE:
                title_init();
                break;

            case SCENE_GAME:
                game_init();
                break;
            case SCENE_GAME2:
                game2_init();
                break;

            case SCENE_RESULT:
                result_init();
                break;

            case SCENE_TUTORIAL1:
                tutorial_init();
                break;
            case SCENE_SELECT:
                select_init();
                break;
            }

            curScene = nextScene;
        }

        // 入力を更新する
        input::update();

        // 音楽の更新処理
        music::update();

        // 現在のシーンに応じた更新・描画処理
        switch (curScene)
        {
        case SCENE_TITLE:
            title_update();
            title_render();
            break;

        case SCENE_GAME:
            game_update();
            game_render();
            break;
        case SCENE_GAME2:
            game2_update();
            game2_render();

        case SCENE_RESULT:
            result_update();
            result_render();
            break;

        case SCENE_TUTORIAL1:
            tutorial_update();
            tutorial_render();
            break;
        case SCENE_SELECT:
            select_render();
            select_update();
            break;
        }

        // デバッグ文字列の描画
        debug::display(1.0f, 1.0f, 1.0f, 1, 1);

        //debug::setString("GP1_09 SAMPLE");

        // バックバッファの内容を表示
        GameLib::present(1, 0);
    }

    // 現在のシーンに応じた終了処理
    switch (curScene)
    {
    case SCENE_TITLE:
        title_deinit();
        break;

    case SCENE_GAME:
        game_deinit();
        break;

    case SCENE_GAME2:
        game2_deinit();
        break;
 
    case SCENE_RESULT:
        result_deinit();
        break;

    case SCENE_TUTORIAL1:
        tutorial_deinit();
        break;
    case SCENE_SELECT:
        select_deinit();
        break;
    }

    // オーディオの終了処理
    audio_deinit();

    // ゲームライブラリの終了処理
    GameLib::uninit();

    return 0;
}