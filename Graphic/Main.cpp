/**
 * @author MCXCC
 * @date 2024/8/9
*/

#include "graphics.h"
#include "conio.h"
#include "Configurations.h"

int main() {
    short recTitlePos[4] = {20, 20, 380, 52};
    short recExitPos[4] = {20, 250, 60, 280};
    short recAboutPos[4] = {80, 250, 128, 280};
    short recAboutTitlePos[4] = {20, 20, 100, 60};
    short recAboutContentPos[4] = {20, 60, 380, 280};
    short width = 400, height = 300;
    RECT recTitle = {recTitlePos[0], recTitlePos[1], recTitlePos[2], recTitlePos[3]};
    RECT recExit = {recExitPos[0], recExitPos[1], recExitPos[2], recExitPos[3]};
    RECT recAbout = {recAboutPos[0], recAboutPos[1], recAboutPos[2], recAboutPos[3]};
    RECT recAboutTitle = {recAboutTitlePos[0], recAboutTitlePos[1], recAboutTitlePos[2], recAboutTitlePos[3]};
    RECT recAboutContent = {recAboutContentPos[0], recAboutContentPos[1], recAboutContentPos[2], recAboutContentPos[3]};
    LOGFONT fontMC;
    LOGFONT fontTitle;
    MOUSEMSG mouse;

    // Initialize Graphics
    initgraph(width, height);

    // Font Setup
    gettextstyle(&fontMC);
    gettextstyle(&fontTitle);
    _tcscpy(fontMC.lfFaceName, _T("Monocraft Nerd Font"));
    _tcscpy(fontTitle.lfFaceName, _T("Monocraft Nerd Font"));
    fontMC.lfQuality = ANTIALIASED_QUALITY;
    fontTitle.lfQuality = ANTIALIASED_QUALITY;
    fontMC.lfHeight = 16;
    fontTitle.lfHeight = 28;

    // GUI Begin
    Menu:
    setbkcolor(bkColor);
    cleardevice();

    // Draw Buttons
    setlinecolor(buttonColor);
    setfillcolor(buttonColor);
    fillrectangle(recTitlePos[0], recTitlePos[1], recTitlePos[2], recTitlePos[3]);
    rectangle(recTitlePos[0], recTitlePos[1], recTitlePos[2], recTitlePos[3]);
    fillrectangle(recExitPos[0], recExitPos[1], recExitPos[2], recExitPos[3]);
    rectangle(recExitPos[0], recExitPos[1], recExitPos[2], recExitPos[3]);
    fillrectangle(recAboutPos[0], recAboutPos[1], recAboutPos[2], recAboutPos[3]);
    rectangle(recAboutPos[0], recAboutPos[1], recAboutPos[2], recAboutPos[3]);

    // Text in Buttons
    setcolor(textColor);
    setbkcolor(buttonColor);
    settextstyle(&fontTitle);
    drawtext("Lagrange Interpolationer", &recTitle, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&fontMC);
    drawtext("Exit", &recExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("About", &recAbout, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    while (true) {
        mouse = GetMouseMsg();
        if (mouse.uMsg == WM_LBUTTONDOWN) {
            if (mouse.x >= recExitPos[0] && mouse.x <= recExitPos[2] && mouse.y >= recExitPos[1] &&
                mouse.y <= recExitPos[3]) {
                closegraph();
                return 0;
            }
            if (mouse.x >= recTitlePos[0] && mouse.x <= recTitlePos[2] && mouse.y >= recTitlePos[1] &&
                mouse.y <= recTitlePos[3]) {
                system("start https://github.com/MCXCC303/Lagrange-Interpolationer");
            }
            if (mouse.x >= recAboutPos[0] && mouse.x <= recAboutPos[2] && mouse.y >= recAboutPos[1] &&
                mouse.y <= recAboutPos[3]) {
                setbkcolor(buttonColor);
                cleardevice();
                setfillcolor(buttonColor);
                setlinecolor(buttonColor);
                fillrectangle(recAboutTitlePos[0], recAboutTitlePos[1], recAboutTitlePos[2], recAboutTitlePos[3]);
                fillrectangle(recAboutContentPos[0], recAboutContentPos[1], recAboutContentPos[2], recAboutContentPos[3]);
                settextstyle(&fontTitle);
                drawtext("ABOUT", &recAboutTitle, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                settextstyle(&fontMC);
                drawtext("Version: 1.0\n\nMade by MCXCC303\nPowered by EasyX\nGitHub: MCXCC303/Lagrange-Interpolationer\nClick \"About\" go back.", &recAboutContent, DT_LEFT | DT_TOP);

                goto About;
            }
            FlushMouseMsgBuffer();
        }
    }
    while (true) {
        About:
        mouse = GetMouseMsg();
        if (mouse.uMsg == WM_LBUTTONDOWN) {
            if (mouse.x >= recAboutTitlePos[0] && mouse.x <= recAboutTitlePos[2] && mouse.y >= recAboutTitlePos[1] &&
                mouse.y <= recAboutTitlePos[3]) {
                setbkcolor(bkColor);
                cleardevice();
                goto Menu;
            }
        }
    }
    getch();
    closegraph();
    return 0;
}