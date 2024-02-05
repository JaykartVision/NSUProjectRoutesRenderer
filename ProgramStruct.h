//#include "RBT.h"
//#include "List.h"
//#include <stdbool.h>
//#ifndef _ProgramStruct_H_
//#define _ProgramStruct_H_
//
//typedef struct Cell
//{
//	char type;
//	int level;
//}Cell;
//
//typedef struct Point
//{
//	int x;
//	int y;
//}Point;
//
//typedef struct KeyPoint
//{
//	int key;
//	int maxRoutes;
//}KeyPoint;
//
//typedef struct DataGraphOutput
//{
//	List* stopovers;
//	float distance;
//	int from;
//	char visited;
//}DataGraphOutput;
//
//typedef struct Map
//{
//	int rows;
//	int cols;
//	Tree* cells;
//	Tree* points;
//	List* nearestPoints;
//	List* waveCells;
//	List* drawRouteCells;
//	char crossRoutes;
//	int countDiag;
//}Map;
//
//typedef struct GraphInput
//{
//	Tree** cities;
//	int countCities;
//}GraphInput;
//
//typedef struct GraphOutput
//{
//	int city;
//	Tree* routes;
//}GraphOutput;
//
//void* InitMap(); /*return map*/
//void ReadInputMap(Map* map);
//void InsertCell(Map* map, int i, int j, char type, int level);
//void InsertPoint(Map* map, int x, int y, char type);
//void InsertNearestPoint(Map* map, int* key);
//int ReturnIntName(char inName);
//char ReturnCharName(int inName);
//int ReturnCountPoints(Map* map);
//char* ReturnTypeCell(Map* map, void* key);
//int* ReturnLevelCell(Map* map, void* key);
//void* ReturnCoord(Map* map, void* inputKey);
//int ReturnKey(Map* map, int x, int y);
//void* ReturnCoordPoint(Map* map, void* inputNamePoint);
//int ReturnKeyPoint(Map* map, void* inputNamePoint);
//int* ReturnSettingMaxRoutesPoint(Map* map, int* name);
//char* ReturnSettingCrossRoutes(Map* map);
//int* ReturnIthNearestPoint(Map* map, int i);
//int ReturnCountNearestPoints(Map* map);
//int* ReturnCountDiag(Map* map);
//void ResetWave(Map* map);
//void ResetNearestPoint(Map* map);
//void* ReturnWaveCells(Map* map);
//void* ReturnDrawRouteCells(Map* map);
//
//void DestrMap(Map* map);
//
//void* InitGraphInput(int countCities); /*return graph*/
//void InsertRoute(GraphInput* graphInput, int* from, void* to, float* distance);
//void IterRoutes(GraphInput* graphInput, GraphOutput* graphOutput, int* nearest, void(*IterFunc)(void* extraData1, void* extraData2, void* inputData, void* inputKey));
//int ReturnCountCities(GraphInput* graphInput);
//void* ReturnDistanceFromTo(GraphInput* graphInput, int* from, void* to);
//void* DeleteRoute(GraphInput* graphInput, int* from, void* to);
//int ReturnCountRoutesFromPoint(GraphInput* graphInput, int* from);
//void DestrGraphInput(GraphInput* graphInput);
//
//void* InitGraphOutput(int city, int countCities); /*return graph*/
////void ClearGraphOutput(GraphOutput* graphOutput);
//int ReturnFromPoint(GraphOutput* graphOutput);
//float* ReturnDistanceRoute(GraphOutput* graphOutput, void* to); /*return unsigned int distance*/
//int* ReturnFromRoute(GraphOutput* graphOutput, void* to); /*return int from*/
//char* ReturnVisitedRoute(GraphOutput* graphOutput, void* to); /*return char visited*/
//void InsertStopover(GraphOutput* graphOutput, void* to, int stopover);
//void DestroyGraphOutputData(void* inputData);
//void DestrGraphOutput(GraphOutput* graphOutput);
//
//#endif