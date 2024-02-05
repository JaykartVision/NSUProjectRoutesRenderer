//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <string.h>
//#include <stdbool.h>
//#include "ProgramStruct.h"
//#include "GUI.h"
//
//void _ResetLevelCell(void* extraData1, void* extraData2, void* inputData, void* inputKey);
//
//int CmpFuncInt(void* inputKey1, void* inputKey2)
//{
//    int* a = (int*)inputKey1;
//    int* b = (int*)inputKey2;
//    if (*a == *b)
//    {
//        return 2;
//    }
//    else
//    {
//        if (*a < *b)
//            return 1;
//        if (*a > *b)
//            return 3;
//    }
//}
//
//void* InitMap()
//{
//    Map* map = (Map*)malloc(sizeof(Map));
//    if (map != NULL)
//    {
//        map->rows = 0;
//        map->cols = 0;
//        map->cells = (Tree*)BstCreate(CmpFuncInt, sizeof(Cell));
//        map->points = (Tree*)BstCreate(CmpFuncInt, sizeof(KeyPoint));
//        map->waveCells = (List*)ListCreate(CmpFuncInt, sizeof(int));
//        map->nearestPoints = (List*)ListCreate(CmpFuncInt, sizeof(int));
//        map->drawRouteCells = (List*)ListCreate(CmpFuncInt, sizeof(int));
//        map->crossRoutes = '0';
//        map->countDiag = 0;
//    }
//    return map;
//}
//
//void ReadInputMap(Map* map)
//{
//    char* text = "Enter fileName:";
//    char fileName[64];
//    EnterString(&fileName, text);
//    FILE* inputFile = NULL;
//    fopen_s(&inputFile, fileName, "r");
//    bool flag = 0;
//    int i = 0;
//    if (inputFile != NULL)
//    {
//        while (!feof(inputFile))
//        {
//            char type = ' ';
//            fscanf_s(inputFile, "%c", &type, 1);
//            if (flag == 0)
//            {
//                flag = 1;
//                switch (type)
//                {
//                case '1':
//                {
//                    InsertCell(map, i, map->rows, '1', -1);
//                    break;
//                }
//                case ' ':
//                {
//                    InsertCell(map, i, map->rows, '0', -1);
//                    break;
//                }
//                default:
//                {
//                    InsertCell(map, i, map->rows, type, -1);
//                    InsertPoint(map, i, map->rows, type);
//                    //printf("DEBUG");
//                    break;
//                }
//                }
//                i++;
//            }
//            else
//            {
//                flag = 0;
//                if (type == '\n')
//                {
//                    if (map->cols == 0) map->cols = i;
//                    i = 0;
//                    map->rows = map->rows + 1;
//                    //printf("DEBUG");
//                }
//                if(feof(inputFile)) map->rows = map->rows + 1;
//            }
//        }
//    }
//}
//
//void InsertCell(Map* map, int i, int j, char type, int level)
//{
//    //Cell* cell = malloc(sizeof(Cell));
//    //if (cell != NULL)
//    //{
//    //    cell->level = level;
//    //    cell->type = type;
//    //    int key = map->cols * map->rows + i;
//    //    BstInsert(map->cells, NULL, cell, &key);
//    //}
//    Cell cell = { type , level};
//    int key = map->cols * j + i;
//    BstInsert(map->cells, NULL, &cell, &key);
//}
//
//void InsertPoint(Map* map, int x, int y, char type)
//{
//    int key = map->cols * y + x;
//    int name = ReturnIntName(type);
//    KeyPoint keyPoint = { key , 0};
//    BstInsert(map->points, NULL, &keyPoint, &name);
//}
//
//int ReturnIntName(char inName)
//{
//    int name = (int)inName - 97;
//    return name;
//}
//
//char ReturnCharName(int inName)
//{
//    char name = (char)(inName + 97);
//    return name;
//}
//
//void InsertNearestPoint(Map* map, int* key)
//{
//    Append(map->nearestPoints, key);
//}
//
//int ReturnCountPoints(Map* map)
//{
//    return BstSize(map->points);
//}
//
//char* ReturnTypeCell(Map* map, void* key)
//{
//    /*int key = y * map->cols + x;*/
//    Cell* cell = BstFind(map->cells, key);
//    return &cell->type;
//}
//
//int* ReturnLevelCell(Map* map, void* key)
//{
//    /*int key = y * map->cols + x;*/
//    Cell* cell = BstFind(map->cells, key);
//    return &cell->level;
//}
//
//void* ReturnCoord(Map* map, void* inputKey)
//{
//    int key = (*(int*)inputKey);
//    Point* point = malloc(sizeof(Point));
//    if (point != NULL)
//    {
//        point->x = key % map->cols;
//        point->y = key / map->cols;
//    }
//    return point;
//}
//
//int ReturnKey(Map* map, int x, int y)
//{
//    return (y * map->rows + x);
//}
//
//void* ReturnCoordPoint(Map* map, void* inputNamePoint)
//{
//    int* key = NULL;
//    *key = ReturnKeyPoint(map, inputNamePoint);
//    return ReturnCoord(map, key);
//}
//
//int ReturnKeyPoint(Map* map, void* inputNamePoint)
//{
//    int* key = BstFind(map->points, inputNamePoint);
//    return *key;
//}
//
//int* ReturnSettingMaxRoutesPoint(Map* map, int* name)
//{
//    KeyPoint* keyPoint = BstFind(map->points, name);
//    return &keyPoint->maxRoutes;
//}
//
//char* ReturnSettingCrossRoutes(Map* map)
//{
//    return &map->crossRoutes;
//}
//
//int* ReturnIthNearestPoint(Map* map, int i)
//{
//    return (int*)Get((map->nearestPoints), i);
//}
//
//int ReturnCountNearestPoints(Map* map)
//{
//    return Length(map->nearestPoints);
//}
//
//void _ResetLevelCell(void* extraData1, void* extraData2, void* inputData, void* inputKey)
//{
//    Cell* cell = (Cell*)inputData;
//    cell->level = -1;
//}
//
//int* ReturnCountDiag(Map* map)
//{
//    return &map->countDiag;
//}
//
//void ResetWave(Map* map)
//{
//    BstForeach(map->cells, _ResetLevelCell, NULL, NULL, NULL);
//    ResetNearestPoint(map);
//}
//
//void ResetNearestPoint(Map* map)
//{
//    FreeList(map->nearestPoints);
//}
//
//void* ReturnWaveCells(Map* map)
//{
//    return map->waveCells;
//}
//
//void* ReturnDrawRouteCells(Map* map)
//{
//    return map->drawRouteCells;
//}
//
//void DestrMap(Map* map)
//{
//    BstDestroy(map->cells, NULL);
//    BstDestroy(map->points, NULL);
//    FreeList(map->nearestPoints);
//    FreeList(map->waveCells);
//    FreeList(map->drawRouteCells);
//    free(map->cells);
//    free(map->points);
//    free(map->nearestPoints);
//    free(map->waveCells);
//    free(map->drawRouteCells);
//    free(map);
//}
//
//void* InitGraphInput(int countCities)
//{
//	GraphInput* graphInput = (GraphInput*)malloc(sizeof(GraphInput));
//	if (graphInput != NULL)
//	{
//		graphInput->countCities = countCities;
//		graphInput->cities = (Tree**)malloc(graphInput->countCities * sizeof(Tree*));
//		for (int i = 0; i < graphInput->countCities; i++)
//		{
//            if (graphInput->cities != NULL)
//            {
//                graphInput->cities[i] = (Tree*)BstCreate(CmpFuncInt, sizeof(float));
//            }
//		}
//	}
//	return graphInput;
//}
//
//void InsertRoute(GraphInput* graphInput, int* from, void* to, float* distance)
//{
//    BstInsert(graphInput->cities[*from], NULL, distance, to);
//}
//
//void IterRoutes(GraphInput* graphInput, GraphOutput* graphOutput, int* nearest, void(*IterFunc)(void* extraData1, void* extraData2, void* inputData, void* inputKey))
//{
//    BstForeach(graphInput->cities[*nearest], IterFunc, graphOutput, nearest, NULL);
//}
//
//int ReturnCountCities(GraphInput* graphInput)
//{
//    return (graphInput->countCities);
//}
//
//void* ReturnDistanceFromTo(GraphInput* graphInput, int* from, void* to)
//{
//    void* item = BstFind(graphInput->cities[*from], to);
//    if (item == NULL)
//    {
//        return NULL;
//    }
//    else
//    {
//        return item;
//    }
//}
//
//void* DeleteRoute(GraphInput* graphInput, int* from, void* to)
//{
//    return BstDelete(graphInput->cities[*from], to);
//}
//
//int ReturnCountRoutesFromPoint(GraphInput* graphInput, int* from)
//{
//    return BstSize(graphInput->cities[*from]);
//}
//
//void DestrGraphInput(GraphInput* graphInput)
//{
//    for (int i = 0; i < graphInput->countCities; i++)
//    {
//        BstDestroy(graphInput->cities[i], NULL);
//    }
//    free(graphInput->cities);
//    free(graphInput);
//}
//
//void* InitGraphOutput(int city, int countCities)
//{
//    GraphOutput* graphOutput = (GraphOutput*)malloc(sizeof(GraphOutput));
//    if (graphOutput != NULL)
//    {
//        graphOutput->routes = (Tree*)BstCreate(CmpFuncInt, sizeof(DataGraphOutput));
//        for (int i = 0; i < countCities; i++)
//        {
//            //int* key = malloc(sizeof(int));
//            //if (key != NULL)
//            //{
//            //    *key = i;
//            //}
//            DataGraphOutput* dataGraphOutput = (DataGraphOutput*)malloc(sizeof(DataGraphOutput));
//            if (dataGraphOutput != NULL)
//            {
//                dataGraphOutput->stopovers = NULL;
//                dataGraphOutput->from = -1;
//                dataGraphOutput->visited = '0';
//                if (i == city)
//                {
//                    dataGraphOutput->distance = 0;
//                }
//                else
//                {
//                    dataGraphOutput->distance = 1e9;
//                }
//                BstInsert(graphOutput->routes, NULL, dataGraphOutput, &i);
//            }
//        }
//        graphOutput->city = city;
//    }
//    return graphOutput;
//}
//
//int ReturnFromPoint(GraphOutput* graphOutput)
//{
//    return graphOutput->city;
//}
//
//float* ReturnDistanceRoute(GraphOutput* graphOutput, void* to)
//{
//    DataGraphOutput* dataGraphOutput = BstFind(graphOutput->routes, to);
//    if (dataGraphOutput != NULL)
//    {
//        return &dataGraphOutput->distance;
//    }
//    else
//    {
//        return NULL;
//    }
//}
//
//int* ReturnFromRoute(GraphOutput* graphOutput, void* to)
//{
//    DataGraphOutput* dataGraphOutput = BstFind(graphOutput->routes, to);
//    if (dataGraphOutput != NULL)
//    {
//        return &dataGraphOutput->from;
//    }
//    else
//    {
//        return NULL;
//    }
//}
//
//char* ReturnVisitedRoute(GraphOutput* graphOutput, void* to)
//{
//    DataGraphOutput* dataGraphOutput = BstFind(graphOutput->routes, to);
//    if (dataGraphOutput != NULL)
//    {
//        return &dataGraphOutput->visited;
//    }
//    else
//    {
//        return NULL;
//    }
//}
//
//void InsertStopover(GraphOutput* graphOutput, void* to, int stopover)
//{
//    DataGraphOutput* dataGraphOutput = NULL;
//    dataGraphOutput = BstFind(graphOutput->routes, to);
//    if (dataGraphOutput->stopovers == NULL) dataGraphOutput->stopovers = ListCreate(CmpFuncInt, sizeof(int));
//    Prepend(dataGraphOutput->stopovers, &stopover);
//}
//
//void DestroyGraphOutputData(void* inputData)
//{
//    DataGraphOutput* data = (DataGraphOutput*)inputData;
//    FreeList(data->stopovers);
//}
//
//void DestrGraphOutput(GraphOutput* graphOutput)
//{
//    BstDestroy(graphOutput->routes, DestroyGraphOutputData);
//    free(graphOutput->routes);
//    /*free(graphOutput);*/
//}