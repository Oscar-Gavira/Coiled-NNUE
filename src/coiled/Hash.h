/*
Coiled is a UCI chess playing engine authored by Oscar Gavira.
Copyright (C) 2013-2021 Oscar Gavira.
<https://github.com/Oscar-Gavira/Coiled>

Coiled is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Coiled is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HASH_H
#define HASH_H

#include "Externo.h"
#include "Utilidades.h"

#ifdef USAR_HASH_TB

// 16 bit short (2 bytes * 8) = 16 bit */
// 0000 0000 0111 1111 */		/*EDAD -  7 bit*/   Valor maximo 127
// 0001 1111 1000 0000 */		/*DEPTH - 6 bit*/   Valor maximo 63
// 0110 0000 0000 0000 */		/*FLAG -  2 bit*/   Valor maximo 3
#define EDAD(e)		((e) & 0x7F)					/* 7bit - rango del 0 al 127 */
#define DEPTH(d)	(((d)>>7) & 0x3F)				/* 6bit - rango del 0 al 63 */
#define FLAG(f)		(((f)>>13) & 0x3)				/* 2bit = 1 o 2 o 3 (ALPHA, BETA, EXACT) */
#define MAX_EDAD	(127)							/* Edad maxima */
#define CELDAS		(3)

/******************************************************************************
Estructuras
******************************************************************************/

/* Estructura para manejar la tabla hash */
typedef struct tag_TT_Opciones
{
	U64 tt_Mb;
	U64 tt_Entradas;
	U64 tt_Completo;
	short tt_Edad;
} _ST_TT_Opciones;

/* Estructura de la tabla hash */
typedef struct	tag_TT_CacheC
{
	U64 Hash;
	int M;
	short Puntos;
	short Ev;
	short Flag;
} _ST_TT_CacheC;

typedef struct	tag_TT_Cache
{
	_ST_TT_CacheC Celdas[CELDAS];
} _ST_TT_Cache;

/******************************************************************************
Variables
******************************************************************************/
/* [Piezas][Tablero] En la matriz pieza, el 0 se utiliza para zobrist de Al Paso y el 7 se utiliza para los Enroque. Y [7][32] para el turno */
U64 zobrist_Tablero[14][64];
_ST_TT_Opciones TT_Opciones;
_ST_TT_Cache *TT_Datos;

/******************************************************************************
							Metodos
******************************************************************************/
/* Guarda Depth, Edad y flag en macro en una variable */
short GuardarFlag(int d, int e, int f);
/* Obtengo el hash inicial */
void ObtenerKey();
/* Creamos la tabla de hash aun tamana especifico */
void CrearTransposicion(U64 MB);
/* Obtengo si la posicion ya a sido analizada y que valores tiene */
int RecuperarPosicion(int *hPuntos, int *hEv, int *hMov, int *hFlag);
/* Convertimos puntosa la TT */
void ConvertirValorTT(int *hPuntos);
/* Se puedo podar mediante TT */
int PodaHash(int *hFlag, int *beta, int *alpha, int *hPuntos);
/* Guardo la posicion analizada */
void AlmacenarPosicion(int depth, int puntos, int hEv, int hFlag, int hMov);
/* Obtenemos el movimiento si esta almacenado */
int RecuperarMovimientoHash();
/* Vacio la tabla hash */
void LimpiarTransposicion();
/* Obtengo el estado de la tabla (Vacia, Medio llena, LLena) % */
int ObtenerHashCompleto();
/* Liberamos la tabla hash */
void LiberarMemoria();

#endif
#endif
