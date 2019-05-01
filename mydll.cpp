#include<stdio.h>
#include"mydll.h"
#include"definition.h"
#include <vector>
#include <queue>
using namespace std;

char Map[] = {
3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,1,1,1,1,3,3,3,3,3,3,3,3,3,3,
3,3,2,2,2,2,3,3,3,1,1,1,1,1,1,1,1,1,1,1,2,0,1,0,0,0,0,0,0,0,0,4,4,4,4,4,5,0,2,1,3,3,3,3,2,2,2,3,3,3,
3,3,2,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,4,4,4,4,4,4,4,6,6,6,4,5,0,2,1,3,3,3,2,3,3,3,3,3,3,
3,3,2,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,4,4,4,4,4,4,4,6,6,6,4,4,4,4,4,3,3,3,2,3,3,3,3,3,3,
3,3,2,2,2,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,2,2,0,5,4,6,6,6,4,1,1,2,4,3,3,3,2,3,3,3,3,3,3,
3,3,2,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,1,1,2,2,0,5,4,4,4,4,4,1,1,2,4,3,3,3,2,3,3,3,3,3,3,
3,3,2,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,2,2,2,0,1,4,4,1,1,2,2,0,0,5,5,4,4,1,1,1,2,4,3,3,3,3,2,2,2,3,3,3,
3,3,3,3,3,3,3,3,3,4,2,2,0,0,0,2,2,1,1,1,1,0,0,4,4,1,1,2,2,2,0,0,0,4,4,1,1,1,2,4,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,4,2,2,0,0,0,2,2,1,1,1,1,0,5,4,4,1,1,2,2,2,2,2,2,4,4,1,1,1,2,4,3,3,3,3,3,3,3,3,3,3,
1,1,1,4,4,4,4,4,4,4,2,2,2,2,2,2,2,1,1,1,1,3,4,4,4,4,4,1,2,2,2,2,2,4,4,1,1,1,2,4,4,4,4,4,4,4,1,1,1,1,
1,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,3,4,7,7,7,4,1,1,1,1,1,1,4,4,1,1,1,2,2,2,2,2,2,2,4,2,2,1,1,
1,0,0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,4,7,7,7,4,4,4,4,4,4,4,4,4,1,1,1,1,2,2,2,2,2,2,4,2,2,1,1,
1,5,5,4,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,3,4,7,7,7,4,4,4,4,4,4,4,4,4,2,2,2,1,2,2,0,0,2,2,4,2,2,1,1,
5,4,4,4,4,4,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,3,4,4,4,4,4,1,1,1,1,1,1,1,1,2,2,2,1,2,2,0,0,2,2,4,2,2,1,1,
5,4,8,8,8,4,4,4,4,4,4,4,4,1,3,2,2,3,3,3,3,3,0,4,4,1,1,3,3,3,3,3,3,3,3,2,2,2,1,2,2,0,0,2,2,4,2,2,1,1,
5,4,8,8,8,4,4,4,4,4,4,4,4,1,3,0,0,0,0,0,0,0,0,4,4,5,1,0,0,0,0,0,0,0,2,2,2,2,1,2,2,2,2,2,2,4,2,2,1,1,
1,4,8,8,8,4,5,0,2,2,1,4,4,1,3,0,1,1,1,1,1,1,1,4,4,1,1,1,1,1,1,1,1,0,2,2,2,2,1,2,2,2,2,2,2,4,2,2,1,1,
1,4,4,4,4,4,5,0,2,2,1,4,4,1,3,0,1,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,1,0,3,1,1,1,1,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,5,5,0,0,2,2,1,4,4,1,3,0,1,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,1,0,3,1,1,1,1,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,0,0,0,2,2,2,1,4,4,1,3,0,1,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,1,0,3,1,1,1,1,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,2,2,2,2,2,2,1,4,4,1,3,0,1,3,3,3,2,1,1,1,1,1,1,1,2,3,3,3,1,0,3,1,1,1,5,1,1,1,1,2,2,4,2,2,1,1,
1,0,4,4,2,2,2,2,2,1,1,4,4,1,3,0,1,3,3,3,1,1,5,0,1,0,5,1,1,3,3,3,1,0,3,3,3,3,3,3,3,0,0,0,0,4,0,0,0,1,
1,0,4,4,1,1,1,1,1,4,4,4,4,4,1,1,1,3,3,3,1,5,4,4,4,4,4,5,1,3,3,3,1,0,0,0,4,4,4,4,4,5,0,1,1,4,1,1,1,1,
1,0,4,4,1,1,1,1,1,4,9,9,9,4,1,5,1,3,3,3,1,0,4,14,14,14,4,0,1,4,4,4,4,4,4,4,4,13,13,13,4,4,4,4,4,4,4,4,2,1,
1,0,4,4,4,4,4,4,4,4,9,9,9,4,4,4,4,4,4,4,1,1,4,14,14,14,4,1,1,4,4,4,4,4,4,4,4,13,13,13,4,4,4,4,4,4,4,4,2,1,
1,0,4,4,4,4,4,4,4,4,9,9,9,4,4,4,4,4,4,4,1,0,4,14,14,14,4,0,1,3,3,3,1,1,5,1,4,13,13,13,4,1,1,1,1,1,4,4,2,1,
1,1,1,1,4,1,1,0,5,4,4,4,4,4,0,0,1,3,3,3,1,5,4,4,4,4,4,5,1,3,3,3,1,1,1,1,4,4,4,4,4,1,1,1,1,1,4,4,2,1,
1,0,0,0,4,0,0,0,0,3,3,3,3,3,3,0,1,3,3,3,1,1,5,0,1,0,5,1,1,3,3,3,1,0,3,1,1,4,4,1,1,2,2,2,2,2,4,4,2,1,
2,2,2,2,4,2,2,1,1,1,1,5,1,1,3,0,1,3,3,3,2,1,1,1,1,1,1,1,2,3,3,3,1,0,3,1,1,4,4,1,2,2,2,2,2,2,4,4,2,1,
1,1,2,2,4,2,2,1,1,1,1,1,1,1,3,0,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,1,0,3,1,1,4,4,1,2,2,2,0,0,0,4,4,2,1,
1,1,2,2,4,2,2,1,1,1,1,1,1,1,3,0,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,1,0,3,1,1,4,4,1,2,2,0,0,5,5,4,4,2,1,
1,1,2,2,4,2,2,1,1,1,1,1,1,1,3,0,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,1,0,3,1,1,4,4,1,2,2,0,5,4,4,4,4,4,1,
1,1,2,2,4,2,2,2,2,2,2,1,2,2,2,0,1,1,1,1,1,1,1,1,4,4,1,1,1,1,1,1,1,0,3,1,1,4,4,1,2,2,0,5,4,12,12,12,4,1,
1,1,2,2,4,2,2,2,2,2,2,1,2,2,2,0,0,0,0,0,0,0,1,1,4,4,0,0,0,0,0,0,0,0,3,1,1,4,4,4,4,4,4,4,4,12,12,12,4,5,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,3,3,3,3,3,3,3,3,1,5,4,4,0,3,3,3,3,3,2,2,3,1,1,4,4,4,4,4,4,4,4,12,12,12,4,5,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,1,1,1,1,1,1,1,1,1,1,4,4,0,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,4,4,4,4,4,5,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,1,1,1,1,1,1,1,1,4,4,4,4,4,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,4,5,5,1,
1,1,2,2,4,2,2,0,0,2,2,1,2,2,4,4,4,4,4,4,4,4,4,11,11,11,4,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,4,0,0,1,
1,1,2,2,4,2,2,2,2,2,2,1,1,1,4,4,4,4,4,4,4,4,4,11,11,11,4,3,5,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,4,2,2,1,
1,1,2,2,4,2,2,2,2,2,2,1,1,1,4,4,1,1,1,1,1,1,4,11,11,11,4,3,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,1,
1,1,1,1,4,4,4,4,4,4,2,1,1,1,4,4,2,2,2,2,2,1,4,4,4,4,4,3,1,1,1,1,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,1,1,1,
3,3,3,3,3,3,3,3,3,4,2,1,1,1,4,4,2,2,2,2,2,1,1,1,4,4,5,0,1,1,1,1,2,2,0,0,0,0,2,2,4,3,3,3,3,3,3,3,3,3,
3,3,3,3,2,3,3,3,3,4,2,1,1,1,4,4,0,0,0,2,2,2,1,1,4,4,0,0,1,1,1,1,2,2,0,0,0,0,2,2,4,3,3,3,3,2,2,3,3,3,
3,3,3,2,2,3,3,3,3,4,2,1,1,1,4,4,5,5,0,0,2,2,1,1,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,4,3,3,3,2,3,3,3,3,3,
3,3,3,3,2,3,3,3,3,4,2,1,1,4,4,4,4,4,5,0,2,2,1,1,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,4,3,3,3,2,3,3,3,3,3,
3,3,3,3,2,3,3,3,3,4,2,1,1,4,10,10,10,4,5,0,2,2,1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,2,2,2,3,3,3,
3,3,3,3,2,3,3,3,3,4,4,4,4,4,10,10,10,4,4,4,4,4,4,4,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,2,3,3,2,3,3,
3,3,3,3,2,3,3,3,3,1,2,0,5,4,10,10,10,4,4,4,4,4,4,4,4,4,1,0,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,2,3,3,2,3,3,
3,3,3,2,2,2,3,3,3,1,2,0,5,4,4,4,4,4,0,0,0,0,0,0,0,0,1,0,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,2,2,3,3,3,
3,3,3,3,3,3,3,3,3,1,1,1,1,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3 };

//1:tree;3:water;4:path;6~14:tower;
/*
基本的四个添加指令的命令
info.myCommandList.addCommand(Produce,aim_tower_id,HeavyArcher);//造兵命令，第二个参数是造兵的塔id，第三个是造的兵种
info.myCommandList.addCommand(Attack,aim_soldier_id,x_position,y_position);//攻击命令，第二个参数是发起攻击的士兵id，第三和第四个参数是目标的x，y位置
info.myCommandList.addCommand(Upgrade,aim_tower_id);//升级命令，第二个参数是欲升级的塔id
info.myCommandList.addCommand(Move,aim_soldier_id,UP,distance);//移动命令，第二个参数是欲移动的士兵id，第三个参数是移动方向，第四个参数是移动距离
*/
#define inf 10000

char cmap(int x, int y) {
	return Map[x + (49 - y) * 50];
}

bool empty(int x, int y) {
	if (x >= 0 && x < 50 && y >= 0 && y < 50) {
		auto t = cmap(x, y);
		return (t != 3 && t < 6);
	} else {
		return false;
	}
}

int dis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int dis(const TPoint& p1, const TPoint& p2) {
	return dis(p1.x, p1.y, p2.x, p2.y);
}

struct odisn {
	int prio,dis, x, y;
	odisn(int a, int b, int c, int d) :prio(a), dis(b), x(c), y(d) {}
};

bool operator<(odisn a, odisn b) {
	return a.prio > b.prio;
}

int odis(int x1, int y1, int x2, int y2,int thres=3) {
	if (!empty(x1, y1)) {
		return inf;
	}
	priority_queue < odisn > que;
	que.push({ dis(x1,y1,x2,y2),0,x1,y1 });
	//printf("looking for (%d,%d) to (%d,%d)\n", x1, y1, x2, y2);
	bool visited[50][50];
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) {
			visited[i][j] = false;
		}
	}
	visited[x1][y1] = true;
	while (!que.empty()) {
		auto p = que.top();
		que.pop();
		int t;
		if ((t = dis(p.x, p.y, x2, y2)) <= thres) {
			//printf("answer is:%d\n", p.dis + t);
			return p.dis + t;
		}
		int tmp = p.dis + 1;
		if (!visited[p.x + 1][p.y] && empty(p.x + 1, p.y)) {
			visited[p.x + 1][p.y] = true;
			que.push({ dis(p.x + 1,p.y,x2,y2),tmp,p.x + 1,p.y });
		}
		if (!visited[p.x - 1][p.y] && empty(p.x - 1, p.y)) {
			visited[p.x + 1][p.y] = true;
			que.push({ dis(p.x - 1,p.y,x2,y2),tmp,p.x - 1,p.y });
		}
		if (!visited[p.x][p.y + 1] && empty(p.x, p.y + 1)) {
			visited[p.x + 1][p.y] = true;
			que.push({ dis(p.x ,p.y + 1,x2,y2),tmp,p.x,p.y + 1 });
		}
		if (!visited[p.x][p.y - 1] && empty(p.x, p.y - 1)) {
			visited[p.x + 1][p.y] = true;
			que.push({ dis(p.x,p.y - 1,x2,y2),tmp,p.x,p.y - 1 });
		}
	}
	return inf;
}

int odis(const TPoint & p1, const TPoint & p2,int thres=3) {
	return odis(p1.x, p1.y, p2.x, p2.y,thres);
}

class AI {
public:
	TSoldier self;
	enum MN {attack_tower,protect_tower,attack_enemy} mission;
	int enemy_lock=-1, tower_lock=-1;
	TPoint target;
	int id;
	bool alive = true;
	AI(int id_) {
		id = id_;
		mission = attack_tower;
	}
	void update(Info& info) {
		alive = false;
		for (auto i : info.soldierInfo) {
			if (i.id == id) {
				self = i;
				alive = true;
				break;
			}
		}
	}
	void move(Info& info) {
		//TODO: add enemy attack 
		if (mission == attack_tower) {
			if (tower_lock >= 0) {
				for (auto i : info.towerInfo) {
					if (i.id == tower_lock) {
						if (i.owner == info.myID) {
							tower_lock = -1;// if the tower is taken down, change target
						}
						break;
					}
				}
			}
			if (tower_lock < 0) {
				int d=inf, id=-1;
				for (auto i : info.towerInfo) {
					if (i.owner == info.myID) {
						continue;
					}
					int tmp = dis(self.position, i.position);
					if (tmp < d) {
						d = tmp;
						id = i.id;
						target = i.position;
					}
				}
				if (id == -1) {
					printf("all clear\n");
					//all tower acquired
				} else {
					tower_lock = id;
				}
			}
			//printf("soldier %d(%d,%d) go to tower %d(%d,%d)\n",self.id,self.x_position,self.y_position, tower_lock,target.x,target.y);
			//info.myCommandList.addCommand(Move, self.id, LEFT, 1);
			if (dis(self.position, target) < self.range + 3) {
				int dx=0, dy=0;
				if (self.x_position > target.x) {
					dx = 1;
				}
				if (self.x_position < target.x) {
					dx = -1;
				}
				if (self.y_position > target.y) {
					dy = 1;
				}
				if (self.y_position < target.y) {
					dy = -1;
				}
				info.myCommandList.addCommand(Attack, self.id, target.x + dx, target.y + dy);
			} else {
				go(info,target);
			}
		}
	}
	void go(Info& info, int x, int y) {
		int dx = 0, dy = 0, mx = self.x_position, my = self.y_position,step=self.move_left;
		struct tmp {
			int dis, dx,dy;
		};
		for (int i = 0; i < step; ++i) {
			if (step <= 0) {
				break;
			}
			int mindis = inf;
			int tdis;
			if (empty(mx + 1, my)) {
				if ((tdis=odis(mx + 1, my, x, y)) < mindis) {
					dx = 1;
					dy = 0;
					mindis = tdis;
				}
			}
			if (empty(mx - 1, my)) {
				if ((tdis=odis(mx - 1, my, x, y)) < mindis) {
					dx = -1;
					dy = 0;
					mindis = tdis;
				}
			}
			if (empty(mx, my + 1)) {
				if ((tdis=odis(mx, my+1, x, y)) < mindis) {
					dx = 0;
					dy = 1;
					mindis = tdis;
				}
			}
			if (empty(mx, my - 1)) {
				if ((tdis=odis(mx , my-1, x, y)) < mindis) {
					dx = 0;
					dy = -1;
					mindis = tdis;
				}
			}
			if (step>=2&&empty(mx + 2, my)) {
				if ((tdis=odis(mx + 2, my, x, y)) < mindis) {
					dx = 2;
					dy = 0;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx - 2, my)) {
				if ((tdis=odis(mx -2, my, x, y)) < mindis) {
					dx = -2;
					dy = 0;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx, my + 2)) {
				if ((tdis=odis(mx , my+2, x, y)) < mindis) {
					dx = 0;
					dy = 2;
					mindis = tdis;
				}
			}
			if (step >= 2 && empty(mx, my - 2)) {
				if ((tdis=odis(mx, my-2, x, y)) < mindis) {
					dx = 0;
					dy = -2;
					mindis = tdis;
				}
			}
			if (mindis != inf) {
				mx += dx;
				my += dy;
				step -= abs(dx) + abs(dy);
				if (dx > 0) {
					info.myCommandList.addCommand(Move, self.id, RIGHT, dx);
				}
				if (dx < 0) {
					info.myCommandList.addCommand(Move, self.id, LEFT, -dx);
				}
				if (dy > 0) {
					info.myCommandList.addCommand(Move, self.id, UP, dy);
				}
				if (dy < 0) {
					info.myCommandList.addCommand(Move, self.id, DOWN, -dy);
				}
			}
			//printf("(%d,%d) to (%d,%d) = (%d,%d)\n", mx, my, x, y, dx, dy);
		}
	}
	void go(Info& info, const TPoint& p) {
		go(info, p.x, p.y);
	}
};


void player_ai(Info& info)
{
	static vector<AI> ai;
	static bool soldiers[1000];
	static bool first_run = true;
	if (first_run) {
		for (int i = 0; i < 1000; ++i) {
			soldiers[i] = false;
		}
		first_run = false;
	}
	for(int i = 0;i<info.towerNum;i++){
		if (info.towerInfo[i].owner == info.myID && !info.towerInfo[i].recruiting) {
			info.myCommandList.addCommand(Produce, i, HeavyArcher);
		}
	}
	for (auto i : info.soldierInfo) {
		if (i.owner == info.myID && !soldiers[i.id]) {
			//printf("add %d(%d,%d)\n", i.id,i.x_position,i.y_position);
			ai.push_back({ i.id });
			soldiers[i.id] = true;
		}
	}
	for (auto i : ai) {
		if (i.alive) {
			i.update(info);
		}
		if (i.alive) {
			i.move(info);
		}
	}
}

 