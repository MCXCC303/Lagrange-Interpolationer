/**
 * @author MCXCC
 * @date 2024/8/9
*/

#include "graphics.h"
#include "Configurations.h"
#include "../SingleValue/SingleValue.h"

int main() {
    // Menu Rectangles Positions
    short recMenuTitlePos[4] = {20, 20, 380, 52};
    short recMenuExitPos[4] = {20, 250, 60, 280};
    short recMenuAboutPos[4] = {80, 250, 128, 280};
    short recMenuSingleValuePos[4] = {20, 100, 120, 180};
    RECT recMenuTitle = {recMenuTitlePos[0], recMenuTitlePos[1], recMenuTitlePos[2], recMenuTitlePos[3]};
    RECT recMenuExit = {recMenuExitPos[0], recMenuExitPos[1], recMenuExitPos[2], recMenuExitPos[3]};
    RECT recMenuAbout = {recMenuAboutPos[0], recMenuAboutPos[1], recMenuAboutPos[2], recMenuAboutPos[3]};
    RECT recMenuSingleValue = {recMenuSingleValuePos[0], recMenuSingleValuePos[1], recMenuSingleValuePos[2],
                               recMenuSingleValuePos[3]};

    // About Rectangles Positions
    short recAboutTitlePos[4] = {20, 20, 100, 60};
    short recAboutContentPos[4] = {20, 60, 380, 280};
    RECT recAboutTitle = {recAboutTitlePos[0], recAboutTitlePos[1], recAboutTitlePos[2], recAboutTitlePos[3]};
    RECT recAboutContent = {recAboutContentPos[0], recAboutContentPos[1], recAboutContentPos[2], recAboutContentPos[3]};

    // Single Value Rectangles Positions
    short recSingleValueTitlePos[4] = {20, 20, 380, 60};
    short recSingleValueResultPos[4] = {20, 100, 380, 280};
    short recSingleValueBackPos[4] = {20, 250, 60, 280};
    short recSingleValueAgainPos[4] = {80, 250, 128, 280};
    RECT recSingleValueTitle = {recSingleValueTitlePos[0], recSingleValueTitlePos[1], recSingleValueTitlePos[2],
                                recSingleValueTitlePos[3]};
    RECT recSingleValueResult = {recSingleValueResultPos[0], recSingleValueResultPos[1], recSingleValueResultPos[2],
                                 recSingleValueResultPos[3]};
    RECT recSingleValueBack = {recSingleValueBackPos[0], recSingleValueBackPos[1], recSingleValueBackPos[2],
                               recSingleValueBackPos[3]};
    RECT recSingleValueAgain = {recSingleValueAgainPos[0], recSingleValueAgainPos[1], recSingleValueAgainPos[2],
                                recSingleValueAgainPos[3]};

    // Single Value Calculation
    char *input;
    input = (char *) malloc(100);
    char *result;

    // Initialize Graphics
    short width = 400, height = 300;
    initgraph(width, height);

    // Font Setup
    LOGFONT fontMC;
    LOGFONT fontTitle;
    gettextstyle(&fontMC);
    gettextstyle(&fontTitle);
    _tcscpy(fontMC.lfFaceName, _T("Monocraft Nerd Font"));
    _tcscpy(fontTitle.lfFaceName, _T("Monocraft Nerd Font"));
    fontMC.lfQuality = ANTIALIASED_QUALITY;
    fontTitle.lfQuality = ANTIALIASED_QUALITY;
    fontMC.lfHeight = 16;
    fontTitle.lfHeight = 28;

    // Mouse Setup
    MOUSEMSG mouse;

    // GUI Begin
    Menu:
    setbkcolor(bkColor);
    cleardevice();

    // Draw Buttons
    setlinecolor(buttonColor);
    setfillcolor(buttonColor);
    fillrectangle(recMenuTitlePos[0], recMenuTitlePos[1], recMenuTitlePos[2], recMenuTitlePos[3]);
    rectangle(recMenuTitlePos[0], recMenuTitlePos[1], recMenuTitlePos[2], recMenuTitlePos[3]);
    fillrectangle(recMenuExitPos[0], recMenuExitPos[1], recMenuExitPos[2], recMenuExitPos[3]);
    rectangle(recMenuExitPos[0], recMenuExitPos[1], recMenuExitPos[2], recMenuExitPos[3]);
    fillrectangle(recMenuAboutPos[0], recMenuAboutPos[1], recMenuAboutPos[2], recMenuAboutPos[3]);
    rectangle(recMenuAboutPos[0], recMenuAboutPos[1], recMenuAboutPos[2], recMenuAboutPos[3]);
    fillrectangle(recMenuSingleValuePos[0], recMenuSingleValuePos[1], recMenuSingleValuePos[2],
                  recMenuSingleValuePos[3]);
    rectangle(recMenuSingleValuePos[0], recMenuSingleValuePos[1], recMenuSingleValuePos[2], recMenuSingleValuePos[3]);

    // Text in Buttons
    setcolor(lightTextColor);
    setbkcolor(buttonColor);
    settextstyle(&fontTitle);
    drawtext("Lagrange Interpolationer", &recMenuTitle, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    settextstyle(&fontMC);
    drawtext("Exit", &recMenuExit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("About", &recMenuAbout, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext("Single Value", &recMenuSingleValue, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    while (true) {
        mouse = GetMouseMsg();
        if (mouse.uMsg == WM_LBUTTONDOWN) {
            if (mouse.x >= recMenuExitPos[0] && mouse.x <= recMenuExitPos[2] && mouse.y >= recMenuExitPos[1] &&
                mouse.y <= recMenuExitPos[3]) {
                closegraph();
                return 0;
            }
            if (mouse.x >= recMenuTitlePos[0] && mouse.x <= recMenuTitlePos[2] && mouse.y >= recMenuTitlePos[1] &&
                mouse.y <= recMenuTitlePos[3]) {
                system("start https://github.com/MCXCC303/Lagrange-Interpolationer");
            }
            if (mouse.x >= recMenuAboutPos[0] && mouse.x <= recMenuAboutPos[2] && mouse.y >= recMenuAboutPos[1] &&
                mouse.y <= recMenuAboutPos[3]) {
                setbkcolor(buttonColor);
                cleardevice();
                setfillcolor(buttonColor);
                setlinecolor(buttonColor);
                fillrectangle(recAboutTitlePos[0], recAboutTitlePos[1], recAboutTitlePos[2], recAboutTitlePos[3]);
                fillrectangle(recAboutContentPos[0], recAboutContentPos[1], recAboutContentPos[2],
                              recAboutContentPos[3]);
                settextstyle(&fontTitle);
                drawtext("About", &recAboutTitle, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                settextstyle(&fontMC);
                drawtext(
                        "Version: 1.0\n\nMade by MCXCC303\nPowered by EasyX\nGitHub: MCXCC303/Lagrange-Interpolationer\nClick \"About\" to back.",
                        &recAboutContent, DT_LEFT | DT_TOP);
                goto About;
            }
            if (mouse.x >= recMenuSingleValuePos[0] && mouse.x <= recMenuSingleValuePos[2] &&
                mouse.y >= recMenuSingleValuePos[1] &&
                mouse.y <= recMenuSingleValuePos[3]) {
                SingleValueBegin:
                // Clear
                setbkcolor(buttonColor);
                cleardevice();
                setfillcolor(buttonColor);
                setlinecolor(buttonColor);

                // Title
                fillrectangle(recSingleValueTitlePos[0], recSingleValueTitlePos[1], recSingleValueTitlePos[2],
                              recSingleValueTitlePos[3]);
                settextstyle(&fontTitle);
                setcolor(lightTextColor);
                drawtext("Single Value Calculation", &recSingleValueTitle, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                // InputBox
                InputBox(input, 100, "Enter the value you want to calculate:\nFormat: 1 3 5 7 114514",
                         "Single Value Calculation");

                // Output
                result = singleValueCalc(input);
                setcolor(buttonColor);
                fillrectangle(recSingleValueResultPos[0], recSingleValueResultPos[1], recSingleValueResultPos[2],
                              recSingleValueResultPos[3]);
                settextstyle(&fontMC);
                setcolor(lightTextColor);
                drawtext(result, &recSingleValueResult, DT_LEFT | DT_WORDBREAK | DT_NOCLIP);

                // Again & Back Button
                setfillcolor(bkColor);
                setcolor(bkColor);
                fillrectangle(recSingleValueAgainPos[0], recSingleValueAgainPos[1], recSingleValueAgainPos[2],
                              recSingleValueAgainPos[3]);
                fillrectangle(recSingleValueBackPos[0], recSingleValueBackPos[1], recSingleValueBackPos[2],
                              recSingleValueBackPos[3]);
                setbkcolor(bkColor);
                setcolor(darkTextColor);
                outtextxy(20, 80, "Result:");
                drawtext("Again", &recSingleValueAgain, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                drawtext("Back", &recSingleValueBack, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                system("del result.txt org.in");
                free(result);
                goto SingleValue;
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
            FlushMouseMsgBuffer();
        }
    }
    while (true) {
        SingleValue:
        mouse = GetMouseMsg();
        if (mouse.uMsg == WM_LBUTTONDOWN) {
            if (mouse.x >= recSingleValueAgainPos[0] && mouse.x <= recSingleValueAgainPos[2] &&
                mouse.y >= recSingleValueAgainPos[1] && mouse.y <= recSingleValueAgainPos[3]) {
                goto SingleValueBegin;
            }
            if (mouse.x >= recSingleValueBackPos[0] && mouse.x <= recSingleValueBackPos[2] &&
                mouse.y >= recSingleValueBackPos[1] && mouse.y <= recSingleValueBackPos[3]) {
                setbkcolor(bkColor);
                cleardevice();
                goto Menu;
            }
            FlushMouseMsgBuffer();
        }
    }
}