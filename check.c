/* 
#include<stdio.h>
#include<stdlib.h>
unsigned int map[2][100][50]=	
	{
		{
			{3}, {2, 2}, {1, 1}, {2, 2}, {3}
		}
		, 
		{
			{3}, {2, 2}, {1, 1}, {2, 2}, {3}
		}
	};
unsigned int userMap[100][100]=
	{
		{0, 1, 1, 1, 0}, 
		{1, 1, 0, 0, 1}, 
		{1, 0, 0, 0, 1}, 
		{1, 1, 0, 1, 1}, 
		{0, 1, 1, 1, 0}
	};

unsigned int mapSize[2]={5,5};
unsigned int mapMaxBlocks[2]={2,2};
*/
unsigned int relayMap[2][50][25];

int check()
{
 	clearMap();
	
	change(userMap);
	
	return compare(relayMap);

}

void clearMap()
{
	int i,j,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<50;j++)
		{
			for(k=0;k<25;k++)
			relayMap[i][j][k]=0;
		}
	}
}

int compare(unsigned int modal[2][50][25])
{	
	int i,j,k,equal=0;
	
	for(i=0;i<mapSize[0];i++)
		{
			{
			for(j=0;j<mapSize[1]/2+mapSize[1]%2;j++)
				if(modal[0][i][j]!=map[0][i][j])
				equal++;
			}
		}
	for(i=0;i<mapSize[1];i++)
		{
			for(j=0;j<mapSize[0]/2+mapSize[0]%2;j++)
			{
				if(modal[1][i][j]!=map[1][i][j])
				equal++;
			}
		}
	
	return !equal;
	
	
}


void change(unsigned int modal[50][50])
{
	int i,j,linesum,rowsum,space;
	for(i=0;i<=mapSize[0]-1;i++)
	{
		linesum=0;
		space=0;
		for(j=0;j<=mapSize[1]-1;j++)
		{
			if(modal[i][j]==0&&j>0&&modal[i][j-1]!=0)
			{
				relayMap[0][i][space]=linesum;
				space++;
				linesum=0;
			}
			else if(modal[i][j]==1)
			{
				linesum++;
			 	if(j==mapSize[1]-1)
				relayMap[0][i][space]=linesum;
			}
		
		}
	}
	
	for(j=0;j<=mapSize[1]-1;j++)
	{
		rowsum=0;
		space=0;
		for(i=0;i<=mapSize[0]-1;i++)
		{
			if(modal[i][j]==0&&i>0&&modal[i-1][j]!=0)
			{
				relayMap[1][j][space]=rowsum;
				space++;
				rowsum=0;
			}
			else if(modal[i][j]==1)
			{
				rowsum++;
				if(i==mapSize[0]-1)
				relayMap[1][j][space]=rowsum;
			}
		}
	}

	
}

