#include "ChessPiece.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>

#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"



King king;
Queen queen;
Bishop bishop;
Knight knight;
Rook rook;
Pawn pawn;



void ChessPiece::placePieces()
{
	//Display light pieces
	{
		glPushMatrix();
		glColor3f(0.25f, 0, 0);

		king.drawBody(0.12, 0, 0.15, 1);
		pawn.drawBody(0.12, 0, 7, 10);

		queen.drawBody(1, -8, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		bishop.drawBody(1, -9, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		bishop.drawBody(1, ((8 * 3) + 1), -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		knight.drawBody(1, +8, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		knight.drawBody(1, -8 * 5, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		rook.drawBody(1, -8, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		rook.drawBody(1, 8 * 7, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		glPopMatrix();
	}

	//Display dark pieces
	{
		glPushMatrix();
		glRotatef(180, 0, 180, 0);
		glColor3f(0, 0, 0.25f);

		glTranslatef(1, 0, 1);

		king.drawBody(0.12, 0, 0.15, 1);
		pawn.drawBody(0.12, 0, 7, 10);

		queen.drawBody(1, -8, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		bishop.drawBody(1, -9, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		bishop.drawBody(1, ((8 * 3) + 1), -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		knight.drawBody(1, +8, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		knight.drawBody(1, -8 * 5, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		rook.drawBody(1, -8, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		rook.drawBody(1, 8 * 7, -7, -10);
		pawn.drawBody(1, 0, 7, 10);

		glPopMatrix();
	}

}