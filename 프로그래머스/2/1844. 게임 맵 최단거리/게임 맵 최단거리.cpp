#include<vector>
#include<queue>
using namespace std;

int dx[] = {1, -1, 0 ,0};
int dy[] = {0, 0, 1, -1};
bool visited[101][101];
int dist[101][101];

void bfs(vector<vector<int> > maps, int x, int y )
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]= true;
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || maps.size()<=nx || ny < 0 || maps[0].size()<=ny)
                continue;
            
            if(visited[nx][ny])
                continue;
            
            if(maps[nx][ny] ==0)
                continue;
            
            visited[nx][ny]=true;
            q.push({nx,ny});
            dist[nx][ny] = dist[cx][cy]+1;
        }
    }

}

int solution(vector<vector<int> > maps)
{
    dist[0][0]=1;
    int answer = 0;
    bfs(maps,0,0);
    
    if(!dist[maps.size()-1][maps[0].size()-1])
        answer= -1;
    else
        answer = dist[maps.size()-1][maps[0].size()-1];
    return answer;
}