#pragma once


#include "stdafx.h"

struct LEVELS {
    int sizex;
	int sizey;
	int pusherx;
	int pushery;
CString element;
};

LEVELS level[61];



void InitLevels ()
{
	level[0].sizex = 22;
	level[0].sizey = 11;
	level[0].pusherx = 13;
	level[0].pushery = 9;
    level[0].element = "    XXXXX                 X   X                 X*  X               XXX  *XXX             X  *  * X           XXX X XXX X     XXXXXXX   X XXX XXXXXXX  ..XX *  *             ..XXXXXX XXXX X@XXXX  ..X    X      XXX  XXXXXX    XXXXXXXX          ";

	level[1].sizex = 14;
	level[1].sizey = 10;
	level[1].pusherx = 8;
	level[1].pushery = 5;
	level[1].element = "XXXXXXXXXXXX  X..  X     XXXX..  X *  *  XX..  X*XXXX  XX..    @ XX  XX..  X X  * XXXXXXXX XX* * X  X *  * * * X  X    X     X  XXXXXXXXXXXX";

	level[2].sizex = 17;
	level[2].sizey = 10;
	level[2].pusherx = 15;
	level[2].pushery = 2;
	level[2].element = "        XXXXXXXX         X     @X         X *X* XX         X *  *X          XX* * X  XXXXXXXXX * X XXXX....  XX *  *  XXX...    *  *   XX....  XXXXXXXXXXXXXXXXXX         ";

	level[3].sizex = 22;
	level[3].sizey = 13;
	level[3].pusherx = 9;
	level[3].pushery = 11;
	level[3].element = "              XXXXXXXX              X  ....X   XXXXXXXXXXXX  ....X   X    X  * *   ....X   X ***X*  * X  ....X   X  *     * X  ....X   X ** X* * *XXXXXXXXXXXX  * X     X       X   X XXXXXXXXX       X    *  XX            X **X** @X            X   X   XX            XXXXXXXXX             ";

	level[4].sizex = 17;
	level[4].sizey = 13;
	level[4].pusherx = 15;
	level[4].pushery = 8;
	level[4].element = "        XXXXX            X   XXXXX        X X*XX  X        X     * XXXXXXXXXX XXX   XX....  XX *  *XXXX....    * ** XX X....  XX*  * @X XXXXXXXXX  *  XX         X * *  X         XXX XX X           X    X           XXXXXX ";

	level[5].sizex = 12;
	level[5].sizey = 11;
	level[5].pusherx = 10;
	level[5].pushery = 2;
	level[5].element = "XXXXXX  XXX X..  X XX@XXX..  XXX   XX..     ** XX..  X X * XX..XXX X * XXXXX * X*  X   X  *X * X   X *  *  X   X  XX   X   XXXXXXXXX";

	level[6].sizex = 13;
	level[6].sizey = 12;
	level[6].pusherx = 6;
	level[6].pushery = 3;
	level[6].element = "       XXXXX  XXXXXXX   XXXX X @XX ** XX    *      XX  *  XXX   XXXX XXXXX*XXXX *  XXX ..X X * * * ...X X    XXX...X X ** X X...X X  XXX XXXXX XXXX         ";

	level[7].sizex = 16;
	level[7].sizey = 17;
	level[7].pusherx = 2;
	level[7].pushery = 7;
	level[7].element = "  XXXX            X  XXXXXXXXXXX  X    *   * * X  X *X * X  *  X  X  * *  X    XXXX *X X  XXXX XX@X* * *  XX   XX    * X*X   X XXX  *    * * * X XXXX  XXXXXXXXX  XXX  XXX        X      X        X      X        X......X        X......X        X......X        XXXXXXXX      ";

	level[8].sizex = 17;
	level[8].sizey = 18;
	level[8].pusherx = 2;
	level[8].pushery = 11;
	level[8].element = "          XXXXXXX          X  ...X      XXXXX  ...X      X      ...X      X  XX  ...X      XX XX  ...X     XXX XXXXXXXX     X *** XX     XXXXX  * * XXXXXXX   X* *   X   XX@ *  *    *  * XXXXXXX ** * XXXXX     X *    X         XXXX XXX            X  X             X  X             X  X             XXXX     ";

	level[9].sizex = 21;
	level[9].sizey = 20;
	level[9].pusherx = 3;
	level[9].pushery = 6;
	level[9].element = "              XXXX            XXXXXX  X            X       X            X  XXXX XXX  XXX  XXXXX XXX    X XX@XXXX   *** X    X X **   ** *   X....XXX  ***X    *  X.....XX *   X ** ** X.....XXXX   X  *    X.....X  X   X * * * X.....X  X XXXXXXX XXX.....X  X   X  * *  X.....X  XXX X ** * *XXXXXXX    X X  *      X        X X *** *** X        X X       X X        X XXXXXXXXX X        X           X        XXXXXXXXXXXXX    ";

	level[10].sizex = 19;
	level[10].sizey = 15;
	level[10].pusherx = 8;
	level[10].pushery = 4;
	level[10].element = "          XXXX          XXXX X  X        XXX  XXX* X       XX   @  *  X      XX  * **XX XX      X  X*XX     X      X X * ** X XXX     X   * X  X * XXXXXXXXX    X  ** X   XXXXX XX *         XX.    XXX  XXXXXXXXX.. ..X XXXX       X...X.X            X.....X            XXXXXXX            ";

	level[11].sizex = 13;
	level[11].sizey = 16;
	level[11].pusherx = 7;
	level[11].pushery = 14;
	level[11].element = "  XXXXXXXXX    X&.&X&.&X    X.&.&.&.X    X&.&.&.&X    X.&.&.&.X    X&.&.&.&X    XXX   XXX      X   X    XXXXXX XXXXXXX           XX * * * * * XXX * * * * XX X* * * * *X  X   *@*   X  X  XXXXX  X  XXXX   XXXX ";

	level[12].sizex = 20;
	level[12].sizey = 13;
	level[12].pusherx = 8;
	level[12].pushery = 5;
	level[12].element = "    XXXXXXXXX         XXX   XX  XXXXX   XXX      X  X   XXXXX  ** X* X  X  ... XX X  *X@*XX X X.X. XX  XX X*  X    ... XX *X    * X X X.X. XX    XX  XX* * ... XX * XX   X  X*X.X. XXX **  *   *  *... X X*  XXXXXX    XX  X X   X    XXXXXXXXXX XXXXX              ";

	level[13].sizex = 17;
	level[13].sizey = 13;
	level[13].pusherx = 8;
	level[13].pushery = 5;
	level[13].element = "XXXXXXXXXXXXXXXX X              X X X XXXXXX     X X X  * * * *X  X X X   *@*   XX XXX X X* * *XXX...XX X   * *  XX...XX XXX*** * XX...XX     X XX XX...XXXXXX   XX XX...X    XXXXX     XXX        X     X          XXXXXXX  ";

	level[14].sizex = 17;
	level[14].sizey = 17;
	level[14].pusherx = 7;
	level[14].pushery = 7;
	level[14].element = "       XXXX          XXXX  X         XX  X  X         X  * * X       XXX X*   XXXX    X  *  XX*   X    X  X @ * X *X    X  X      * XXXX XX XXXX*XX     X X *X.....X X   X X  *...&. *X XXXXX  X.....X   X  X   XXX XXXXXXX  X **  X  X       X  X     X       XXXXXX   X            XXXXX       ";

	level[15].sizex = 14;
	level[15].sizey = 15;
	level[15].pusherx = 4;
	level[15].pushery = 6;
	level[15].element = "XXXXX         X   XX        X    X  XXXX  X *  XXXX  X  X  ** *   *X  XXX@ X*    XX  X  XX  * * XX X *  XX XX .X X  X*XX*  X.X XXX   *..XX.X  X    X.&...X  X ** X.....X  X  XXXXXXXXX  X  X          XXXX        ";

	level[16].sizex = 18;
	level[16].sizey = 16;
	level[16].pusherx = 11;
	level[16].pushery = 3;
	level[16].element = "       XXXXXXX     XXXXXXX     X     X     X *@* X     X** X   XXXXXXXXX X XXX......XX   X X   *......XX X X X XXX......     XXX   XXXX XXX X*XXX  X*   X  *  X X X  * ***  X *XX X X   * * XXX** X X XXXXX     *   X X     XXX XXX   X X       X     X   X       XXXXXXXX  X              XXXX ";

	level[17].sizex = 22;
	level[17].sizey = 13;
	level[17].pusherx = 16;
	level[17].pushery = 3;
	level[17].element = "      XXXXXXXXXXXX          X  .  XX   X          X X.     @ X     XXXXXX XX...X XXXX   XX  XX...XXXX     XXXXX * XX...    * X  *  XX     .. XX X XX XX  XXXXX*XXX*X *  X   X XX XXX  X    XX* ** X X  X   ** X X * X *XX X  X                  X  XXXXXXXXXXXXXXXXX  X                  XXXX ";

	level[18].sizex = 28;
	level[18].sizey = 20;
	level[18].pusherx = 13;
	level[18].pushery = 2;
	level[18].element = "        XXXXXX                      X   @XXXX                 XXXXX *   X                 X   XX    XXXX              X *XX  XX    X              X   X  XXXXX X              X X** *    X X              X  * * XXX X X              X X   *  X X X              X X  X*X   X X             XX XXXX   X X X             X  *  XXXXX X X XXXX       XX    *     *  XXX  XXXXXXXXX  XXX * *X * X   .....XX     XX      X  XX  X.....XX ****    XXXXXX*XX   X.XX.XXX    XX              X....X XX  XXXXXXXXXXXXXXX   ....X  X  X             XXXXX  XX  XXXX                 XXXX ";

	level[19].sizex = 20;
	level[19].sizey = 20;
	level[19].pusherx = 7;
	level[19].pushery = 5;
	level[19].element = "       XXXXXXXXXXXX        X..........X      XXX.X.X.X.X..X      X   .........X      X@ * * * &.&.X     XXXXXXX XXXXXXX  XXXX   X    XX  X  XX    * X    X * XX X  X*X XXX XXX*   XXX *  * *   X * * * XX  X * XX       X* XX   *XXXX*XXXX*XX  XXXXX  XX   X    X  X   X* XX   X X **  X   X   X * X  *    X   XXX X ** X  * XXX     X X    X * XX       X XXXXXXXX X        X          X        XXXXXXXXXXXX   ";

	level[20].sizex = 16;
	level[20].sizey = 14;
	level[20].pusherx = 3;
	level[20].pushery = 11;
	level[20].element = "   XXXXXXXXXX      X..  X   X      X..      X      X..  X  XXXX   XXXXXXX  X  XX  X            X  X  X  XX  X  XXXXX XX  XXXX XXX  *  XXXXX X  XX X *  *  X *  XX @*  *   X   XXXXXX XX XXXXXXX    X    X          XXXXXX       ";

	level[21].sizex = 22;
	level[21].sizey = 20;
	level[21].pusherx = 12;
	level[21].pushery = 5;
	level[21].element = "            XXXX       XXXXXXXXXXXX  XXXXX   X    X  X  *  X   XX  X * * *  * X * *   X  XX* *   X @X *   * X XXX   XXXXXXXXXXXX XX X  * *X  X......X *X  X X   X  X......XX X  X  XX XX X .....X  X  X X      *...... * X  X X * XX X......X  X  X  * *X  X......X *X  X *   X  XX*XXXXX  X  X * * XXXX * *  * *X  XX X     * * * *   XXX X  XXXXXX *    *    X X         X XXXXXXX X XXXXXXX X*          X       X   XXXXXXXXXXX       XXXXX          ";

	level[22].sizex = 25;
	level[22].sizey = 14;
	level[22].pusherx = 6;
	level[22].pushery = 8;
	level[22].element = "       XXXXXXX                  X  X  XXXX               X *X* X  XX       XXXXXXXX  X  X   XXXXXXXXX....  X *X* X  *X  X   XX....X X     X*  X      XX..X.    *X  X *    X*  XX... @XX  X* X*  X  X   XX.... XX *X     *XXXXXXXXXXXXXXXX  X**X*  X              X *X  X  *X              X  X  X   X              XXXX  XXXXX                 XXXX           ";

	level[23].sizex = 21;
	level[23].sizey = 19;
	level[23].pusherx = 6;
	level[23].pushery = 16;
	level[23].element = "   XXXXXXXXXX           X........XXXX        X.X.X....X  X        X........** X        X     .XXX  XXXX   XXXXXXXXX  * X   X   X     *   * *  * X   X  X    X  * *X  X   XX XXXXX   X  X  X   X *     X   XXXX X  XX  *X   X XX  X  X  X    XX*XXX    X  XX X *    * X  X  X   X XXXXX    X XX X XX XX    X*X X  *  * *   X    X@X  *X***  X   X    XXX  *      XXXXX      XX  X  X  X           XXXXXXXXXX    ";

	level[24].sizex = 23;
	level[24].sizey = 17;
	level[24].pusherx = 18;
	level[24].pushery = 10;
	level[24].element = "               XXXX              XXXXXX  XXXXX    XXXXXXX       X   X    X      * * XX X X X    X  XXXX *  X     .X    X      * X X XX.X.X    XX*XXXX* * * XX.X.X    X     X    XXXX.XXX    X *   XXXXXX  X.X.XXXXXXX***XX      @X.X.XX      X    X*X*XXX. .XX XXXX X*****    X ...XX X    *     X   X ...XX X   XX XX     XXX...XX XXXXXX*XXXXXX  XXXXXXX        X    X  X     XXXXXXXXXX    XXXX     ";

	level[25].sizex = 15;
	level[25].sizey = 15;
	level[25].pusherx = 5;
	level[25].pushery = 5;
	level[25].element = "XXXXXXXXX      X       X      X       XXXX   XX XXXX X  X   XX X@XX    X   X *** *  **X   X  X XX *  X   X  X XX  * XXXXXXXX  *** *X  X X   XX   ....X X X   X X.. .X X   X X XX...X XXXXX *  X...X     XX   XXXXX      XXXXX    ";

	level[26].sizex = 23;
	level[26].sizey = 13;
	level[26].pusherx = 11;
	level[26].pushery = 12;
	level[26].element = " XXXXXXXXXXXXXXXXX      X...   X    X   XXX   XX.....  *XX X X * X   X......X  *  X  *  X   X......X  X  X X X XX  XXXXXXXXX *  * X X  XXX  X     X*XX* XX XX   X XX   *    X *  *   X X X  XX XXX X  XXXXX*X X X * **     *   *     X X *    *XX* XXXXXXXX X XXXXXXX  @ XX      XXX       XXXXXX          ";

	level[27].sizex = 15;
	level[27].sizey = 17;
	level[27].pusherx = 7;
	level[27].pushery = 2;
	level[27].element = "     XXXXXXX        X@ X  X        X *   X       XXX XX X    XXXX *  X XX   X       X  XX  X * *XXXX * X  X ** X  X  *X  X*  *   X*  X XX  **X   ** XXX **  X  X  * XX     XXXX *  XX  X*XX..XX   XXXX .X....XXXXX  X .......XX    X....   ..X    XXXXXXXXXXX  ";

	level[28].sizex = 24;
	level[28].sizey = 11;
	level[28].pusherx = 20;
	level[28].pushery = 10;
	level[28].element = "                XXXXX          XXXXXX XXX   XXXX   XXXXX    XXX * *  * XXXXX  XX X* *    * X   XX....   ** * *  *   X*XXX.. X XX X   XXX*XX X  XX....    X XXX    X    XX....    X XX  *  XXX* XX..XXXXXX  *  X  XXXX XXXXXX    X   XXX    @  X         XXXXXXXXXXXXXXX ";

	level[29].sizex = 14;
	level[29].sizey = 20;
	level[29].pusherx = 9;
	level[29].pushery = 7;
	level[29].element = " XXXXX         X   XXXXXXX   X * XXX   X   X *    ** X   XX XXXX   X  XXX X  X XXX  X   X  X@XX   X **    * X   X   X X * XXXXXXXXX X   X  X X   *XXXX   X X  *     *  X XX   XXXXX XX XXXXXXXXXX  XXX....X *  * XX.....X **X  XX.. ..X *  * XX.....*   X  XXX  XXXXXXXXXX XXXX         ";

	level[30].sizex = 15;
	level[30].sizey = 12;
	level[30].pusherx = 14;
	level[30].pushery = 10;
	level[30].element = " XXXXXXX        X  X  XXXXX   XX  X  X...XXX X  *X  X...  X X * X** ...  X X  *X  X... .X X   X *XXXXXXXXXX*       * * XXX  X  ** X   X XXXXXX  XX**@X      X      XX      XXXXXXXX ";

	level[31].sizex = 18;
	level[31].sizey = 16;
	level[31].pusherx = 9;
	level[31].pushery = 3;
	level[31].element = "  XXXX              X  XXXXXXXXX     XX  XX @X   X     X  *X * *   XXXX  X*  *  X * *X  XXXX  *XX X* *     XX  X  X X   ***  XX *    *  *XX XXXXX * * X*X  X  X   XX  XXX  XXX* X    X  X....     X    XXXX......XXXX      X....XXXX         X...XX            X...X             XXXXX          ";

	level[32].sizex = 13;
	level[32].sizey = 15;
	level[32].pusherx = 2;
	level[32].pushery = 5;
	level[32].element = "      XXXX     XXXXX  X    XX     *X   XX *  XX XXX X@* * X *  X XXXX XX   *X  X....X* * X  X....X   *X  X....  ** XX X... X *   X XXXXXX* *  X      X   XXX      X* XXX       X  X         XXXX   ";

	level[33].sizex = 12;
	level[33].sizey = 15;
	level[33].pusherx = 11;
	level[33].pushery = 11;
	level[33].element = "XXXXXXXXXXXXXX     XX  XXX   *   * XXXXX XX ** XX   * X    XX *** X XXXXX   X X * XXX  X  X  * XX *X *X    XX   ..X XXXXXXXX.. * X@XX.....X *X XXX....X  * XXXX..XX    XXXXXXXXXXXXX";

	level[34].sizex = 20;
	level[34].sizey = 16;
	level[34].pusherx = 11;
	level[34].pushery = 2;
	level[34].element = "XXXXXXXXXXXX  XXXXXXX   X    X@XXXX....XX   **X       .....XX   X XXX   XX ....XXX XX XXX  X   ....X X * *     X XX XXXX X  * *XX  X       XXXXX X  XXXX XX XX XX  X X*   XX XX    XX *  *  X XX XXXXXXXX X * *    X X      X  * XX XX X X      X **     **  X      XX XX XXX *  X       X    X X    X       XXXXXX XXXXXX      ";

	level[35].sizex = 18;
	level[35].sizey = 19;
	level[35].pusherx = 8;
	level[35].pushery = 9;
	level[35].element = "     XXXX            XXX  XX        XXXX  *  X        X   * *  XXXX     X *   X *   X XXXXX  X  X   * X X..XXX*X* XXXX*XXXX..X X   XXXXX XX ...X X*X XX@XX XX  ..X X X    *     ...X X   XXXX XXX  ..X XXX XX X  XX ...X  XX* XXXX* XXX..X  X   XX    X X..X XX **XX  * X XXXX X     **** X      X * XXX    X      X   X XXXXXX      XXXXX            ";

	level[36].sizex = 21;
	level[36].sizey = 15;
	level[36].pusherx = 10;
	level[36].pushery = 14;
	level[36].element = "XXXXXXXXXXX          X......   XXXXXXXXX  X......   X  XX   X  X..XXX *    *     X  X... * * X  XXX   X  X...X*XXXXX    X  X  XXX    X   X*  X *XXX  X  ** * *  *XX  * X  X  *   X*X  XX    X  XXX XX X  * XXXXXXX   X  * * XX XX         X    *  *  X         XX   X X   X          XXXXX@XXXXX              XXX          ";

	level[37].sizex = 14;
	level[37].sizey = 15;
	level[37].pusherx = 11;
	level[37].pushery = 4;
	level[37].element = " XXXXXXXXX     X....   XX    X.X.X  * XX  XX....X X @XX X ....X  X  XXX     X* XX* XXX XXX  *    X X*  * * *X  X X X  * * XX X X  XXX  XX  X X    XX XX XX X  * X  *  X  XXX* *   XXX    X  XXXXX      XXXX       ";

	level[38].sizex = 23;
	level[38].sizey = 18;
	level[38].pusherx = 12;
	level[38].pushery = 6;
	level[38].element = "              XXX                   XX.XXX                 X....X     XXXXXXXXXXXXX....X    XX   XX     XX....XXXXXX  **XX  * @XX....    XX      ** *X  ....X   XX  * XX ** X X....X  XXX  * XX *  X XX XXX  X XX XXXXX XXX         X XX   *  * XXXXX XXX  X X *XXX  X XXXXX X XXXX X   *   X       X      X  * X* * *XXX  X      X ***X *   X XXXX      X    X  ** X           XXXXXX   XXX                XXXXX             ";

	level[39].sizex = 11;
	level[39].sizey = 11;
	level[39].pusherx = 9;
	level[39].pushery = 2;
	level[39].element = "      XXXX XXXXXXX @X X     *  X X   *XX *X XX*X...X X  X *...  X  X X. .X XX X   X X* X X*  *    X X  XXXXXXX XXXX      ";

	level[40].sizex = 20;
	level[40].sizey = 15;
	level[40].pusherx = 18;
	level[40].pushery = 9;
	level[40].element = "           XXXXX              XX   XX            XX     X           XX  **  X          XX **  * X          X *    * X   XXXX   X   ** XXXXX X  XXXXXXXX XX    X X..           ***@X X.X XXXXXXX XX   XX X.X XXXXXXX. X* *XXXX........... X   * XXXXXXXXXXXXXXX  *  X             XX  XXX              XXXX  ";

	level[41].sizex = 13;
	level[41].sizey = 18;
	level[41].pusherx = 3;
	level[41].pushery = 2;
	level[41].element = " XXXXXXXX     X@XX   XXXX  X *   *   X  X  * * ***X  X **X X   X XX*    *   X X  *  *****XXX *XXXX X   XX  *....X   XX XX....X** XX XX....   XXX   ....X  X XX X....X**X  X X....X  X  X         X  XXXX XX*XXX     X    X       XXXXXX   ";

	level[42].sizex = 17;
	level[42].sizey = 16;
	level[42].pusherx = 16;
	level[42].pushery = 4;
	level[42].element = "    XXXXXXXXXXXX     X          XX    X  X X** *  X    X* X*X  XX @X   XX XX X * X XX   X   * X*  X X    X   X *   X X    XX * *   XX X    X  X  XX  * X    X    XX **X X XXXXXX**   X   X X....X  XXXXXXXX X.X... XX        X....   X        X....   X        XXXXXXXXX        ";

	level[43].sizex = 25;
	level[43].sizey = 19;
	level[43].pusherx = 14;
	level[43].pushery = 8;
	level[43].element = "      XXXXXX                XXXXX   X                X   X X XXXXX            X * X  *    XXXXXX      XX*  XXX XX       X    XXX  ** * * X  XX   XXXXXX       *   XXXXXX XX   XX  XXXXXXXX X@   X X  X XXX XXX      XXXX X*X X  X X XXX XXXX XX.. X   * XX X  *  *  X*XX.. X*XX  XX X  X X X     ..XX XX * X XXXX   X XX X..X    *  X    XXXXX    X..X X X  XX        XXXXXX..X   X XX              X..XXXXX  X              X..       X              XX  XXX  XX               XXXXXXXXX  ";

	level[44].sizex = 19;
	level[44].sizey = 11;
	level[44].pusherx = 10;
	level[44].pushery = 8;
	level[44].element = "        XXXXXXX        XXXXX  X  XXXX     X   X   *    X  XXXX X** XX XX  X XX      X X  XX XXXX  XXX *X*  *  *  XX...    X XX  X   XX...X    @ X XXX XXX...X  XXX  *  *  XXXXXXXXX XX   X   X          XXXXXXXXX";

	level[45].sizex = 22;
	level[45].sizey = 17;
	level[45].pusherx = 12;
	level[45].pushery = 15;
	level[45].element = "    XXXXXXXXX  XXXX       X   XX  XXXX  X       X   *   X  *  X       X  X XX X     XXXX    XX *   * **X X   X    XXXX  X  X * *   XXXXXX  XXXX    XXX...XX   X* X  X XXXX.....XX      X  X X XX.....XXXXXXX X  X*   XXX...X   X   XX X *X   X...X  XX       *  *X XXXXX XX ***XX  X *   X     X   X  X XXX  XXX     X   *  X* @XXXX       XXXXX  X   X              XXXXXXXX         ";

	level[46].sizex = 19;
	level[46].sizey = 15;
	level[46].pusherx = 10;
	level[46].pushery = 4;
	level[46].element = " XXXXX              X   X              X X XXXXXX         X      *@XXXXXX    X * XX* XXX   X    X XXXX *    * X    X XXXXX X  X* XXXXXX  XXXX XX*      XX  *X  *  X XX XX XX         X X...X XXXXXXX  XXX  ...  X     XXXX X X...X X          X XXX X X          X       X          XXXXXXXXX";

	level[47].sizex = 16;
	level[47].sizey = 15;
	level[47].pusherx = 8;
	level[47].pushery = 12;
	level[47].element = "       XXXX            X  XX           X   XX          X ** XX       XXX*  * XX   XXXX    *   X XXX  X XXXXX  X X    X X....* X X X   * ....X X X  * X X.&..X X XXX  XXXX XXX X   XXXX @*  XX*XX     XXX *     X       X  XX   X       XXXXXXXXX";

	level[48].sizex = 19;
	level[48].sizey = 16;
	level[48].pusherx = 3;
	level[48].pushery = 8;
	level[48].element = "      XXXXXXXXXXXX      XX..    X   X     XX..& *    * X    XX..&.X X X* XX    X..&.X X X *  X XXXX...X  X    X X X  XX X          X X @* * XXX  X X XX X *   *   X X   X  XXX**   X X X X X    X   *   X X XXXXX  X *X XXXXX      X  X*   X   X   X  X  X  XXX   XX     X  X  X      X    XX  XXXX      XXXXXX ";

	level[49].sizex = 21;
	level[49].sizey = 16;
	level[49].pusherx = 6;
	level[49].pushery = 10;
	level[49].element = "     XXXXXXXXXXXXX        X    XXX    X        X     * *  XXXX    XXXX X   * *    X   XX *  X*XXXX * * X XXX   X X   XXX  * X X *  *  X  *  X XXXX X XX*XXXX X*X  *  XXXX XX  XXX X X X  *  XX    @*   *   X * X XXXXXX  X  XX  X *X  X  X... XXXXX*  X  X X  X.......X ** X* X X  X.......X         X  X.......XXXXXXX  XX  XXXXXXXXX     XXXX ";

	level[50].sizex = 16;
	level[50].sizey = 14;
	level[50].pusherx = 6;
	level[50].pushery = 10;
	level[50].element = "XXXXX XXXX      X...X X  XXXX   X...XXX  *  X   X....XX *  *XXX XX....XX   *  X XXX... XX * * X X XX    X  *  X X  XX X XXX XXXXX * X X*  *    XX  * @ *    *  XX   X * ** * XXXX  XXXXXX  XXX  X XX    XXXX    XXX             ";

	level[51].sizex = 21;
	level[51].sizey = 14;
	level[51].pusherx = 6;
	level[51].pushery = 13;
	level[51].element = " XXXX                XX  XXXXX            X       X XXXXX      X *XXX  XXX   X      X..X  *X X  X X      X..X      **X XXX    X.&X X  X* *    XXXXXX..X  XX     XX*X   XX.&*  * X XX  *     XX..XX  *   X   XXXXXXX.&XX*XX   XXXXX     X..  * XXXXX         X  X @ X             XXXXXXXX             ";

	level[52].sizex = 13;
	level[52].sizey = 19;
	level[52].pusherx = 5;
	level[52].pushery = 8;
	level[52].element = "   XXXXXXXXXX   X  XXX   X   X *   *  X   X  XXXX*XX   XX X  X  X  XX  X.&   X  X  XX..X  X  X @ X.&X XX  X X*X..X* X  X * X..X  X  X X X&&X  X  X * X..X*XX  X    .&X  X XXX  X  X  XXX    XXXX  XX  XXXXXXX*XXX *      *  XX  XX   X   XXXXXXXXXXXXXX";

	level[53].sizex = 23;
	level[53].sizey = 20;
	level[53].pusherx = 5;
	level[53].pushery = 12;
	level[53].element = " XXXXXXXXXXXXXXXXXXXXX  X   XX  X   X   X   X  X *     *   *   *   XXXXXXX X  X   XXX XX*XXXX   X XX*XXXXXX   X   XX *   X ......X   X * XXX X  X ......XXXXX   XXX XXXXXXXXX..X   X XXXX          X..X *   X  X XX XXX XXX..XX X  XXXX X   X   XX..XX XXX  XX   @      *..X       XX X   X   XX  X   XX  XXXXXX XXXXXXXXXXXXXX XXX          X   X    * XX *  X * * *   X X    XX X*XX *X  XX XX    X XX  * ** XXXX *  * X X XX          X   X      XXXXXXXXXXXXXXXXXXXXXXXX";

	level[54].sizex = 22;
	level[54].sizey = 15;
	level[54].pusherx = 6;
	level[54].pushery = 9;
	level[54].element = " XXXXXXXXXXXXXXXXXXXXXXX                   XX    * X      XX X   XX  XXXXXX XXX  X*XX XXXX*X   XX*X....   X X X  X    * X....XX X X X * X X X X....XX   X X * X**   X....XX*X X X X *@*XX*X....XX   X X   ***   X....X    X X  *X   X XXXXXX *XXX XX  X XXX**  *   * X  XX     X *  * XX   X   XXXXX   X   XXXXXXX       XXXXXXXXX        ";

	level[55].sizex = 14;
	level[55].sizey = 16;
	level[55].pusherx = 12;
	level[55].pushery = 8;
	level[55].element = "XXXXXXXXXX    X        XXXX X XXXXXX X  XXX X * * *  * XX       X*   XXXX*  **X  XXX  X  XX X *XX   XX*X   * @X    X  * * XXX    X X   *  X    X XX   X X   XX  XXXXX X   X         X   X.......XXX   X.......X     XXXXXXXXX   ";

	level[56].sizex = 18;
	level[56].sizey = 11;
	level[56].pusherx = 8;
	level[56].pushery = 6;
	level[56].element = "         XXXX      XXXXXXXXX  XX    XX  *      * XXXXXX   XX XX   XX...XX X** * **X*XX...XX X    @  X   ...XX  *X XXX**   ...XX *  **  * XX....XXXX*       XXXXXXX  X  XXXXXXX        XXXX            ";

	level[57].sizex = 27;
	level[57].sizey = 20;
	level[57].pusherx = 22;
	level[57].pushery = 15;
	level[57].element = "              XXXXXX                 XXXXX    X                 X  XX X  XXXXX             X   &.X..X   X    XXXXX XXXX *X.X...    X    X   XXX  XX X&....XX XX    X *      XX X..X..XX X    XXXXXX X   X X&.XXXXX X    X   X *X*X X X..XXXXX X    X *  *     X X&.    X X    XX XX  * XXX X  XX  X X     X  *  * XXX XXXXX XX X     XXX*XXX*XXX  XXXX XX X    XXXX X         XXX  X X    X  * X  *XXXX  XXX**X@XXXXXX      * X X  XXXX  X*X   XXXXX X  *X X              X   X  *  X XX  XX  XXXXXXXX   XX  XXX  XXXXXXXX           XXXX                   ";

	level[58].sizex = 29;
	level[58].sizey = 20;
	level[58].pusherx = 14;
	level[58].pushery = 14;
	level[58].element = "         XXXX                         X  X                         X  XXXXXXXX            XXXXXXX  X      X            X   X X X X X   XX           X *     *  XX  * X          XXX *X X  X X     XXXXXXXXX  X  *  X  *X X ** X   X X  X XX X   X     XXX    * X X  X X  X*   X XXX  X  X **X X  X X    *XX *  X   XX *  X X XXXXXX* * X    XX  X   *    ..XX  X    XXX X * * XXX  XXX.&XX     XX  ** @  *     XX....XX  XX  XX   *  X*X  XX....&.XXX X  *  X X *XX  XX....&.XXXXX XX  *  X * X  X....&.XXX  X    * XXXX   X ....&.XXX    X   X  X  X  X  ..&.XXX      XXXXXXXX  XXXXXXXXXXX        ";

	level[59].sizex = 26;
	level[59].sizey = 16;
	level[59].pusherx = 7;
	level[59].pushery = 9;
	level[59].element = "        XXXXX                     X   XXXX                  X *    XXXX  XXXX         X   X *X  XXXX  X XXXXXXXXXXX X   *   X   X X..     X *  XXXX X  X  X X..*  X   *  X  * X * .XX X.&X X * * XX  XX    X.X  X..X* @ X   XX    ** X.X  X..X * *  * * XX   XX .X  X.&** X XX   * X*X * X.X  X..X      XX   X     X.X  X..XXXXXXX  XXX XXXXXX.XX X **                  &.XXX  XXXXXXXXXXXXXXXXXX  ..XXXXX                XXXXXX";

	level[60].sizex = 22;
	level[60].sizey = 11;
	level[60].pusherx = 13;
	level[60].pushery = 9;
    level[60].element ="    XXXXX                 X   X                 X   X               XXX   XXX             X       X           XXX X XXX X     XXXXXXX   X XXX XXXXXXX    XX             *     .XXXXXX XXXX X@XXXX    X    X      XXX  XXXXXX    XXXXXXXX          ";






















































































};

