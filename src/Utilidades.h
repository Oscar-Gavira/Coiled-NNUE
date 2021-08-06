/*
Coiled-NNUE is a UCI chess playing engine authored by Oscar Gavira.
<https://github.com/Oscar-Gavira/Coiled-NNUE>

Coiled-NNUE is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Coiled-NNUE is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef UTILIDADES_H
#define UTILIDADES_H

/******************************************************************************
							M�todos
******************************************************************************/
void ImprimirMovimientoCoordenadas(int Inicio, int Fin, int PiezaCoronacion);		/* Imprimir el movimiento en coordenadas E2E4 */
void MovimientoCoordenadas(int Inicio, int Fin, int PiezaCoronacion, char *mov);	/* Obtenemos el movimiento en coordenadas E2E4 */
char *Split_String(char *string, char *contenedor, int longitud);					/* Limpiamos cadenas con espacios */
U64 ObtenerTiempo();																/* Obtenemos el tiempo */
int Entrada_StdIn();																/* Comprobamos entradas durante la b�squeda. */
int ValorPieza(int Pieza);															/* Obtenemos el valor de la pieza */
int Es_Numero(char *p);																/* Comprueba si una cadena es num�rica (sin decimales, para los par�metros UCI) */
int Es_Un_Numero(char c);															/* Verifica si es un num�rico */
int IndexOf_shift(char *base, char *str, int startIndex);							/* Devuelve el indice de la coincidencia dentro de un string. Si no hay devuelve -1 */
#endif
