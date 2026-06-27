/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20)。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。

两军的司令部都会制造武士。武士一共有dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n 个武士，编号就是n。同样，蓝方制造出来的第n 个武士，编号也是n。

武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

sword的攻击力是使用者当前攻击力的20%(去尾取整)。

bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。

arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。

武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：

在奇数编号城市，红武士先发起攻击

在偶数编号城市，蓝武士先发起攻击

战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。若有多支arrow，用过的排在前面。排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。每使用一件武器，被攻击者生命值要减去武器攻击力。如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。

双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。

如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。

有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。

战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。如果有多件arrow，优先缴获没用过的。

如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。

不同的武士有不同的特点。

编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。

编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。

编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。

编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。

wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。

以下是不同时间会发生的不同事件：

在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon 的顺序制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf 的顺序制造武士。

制造武士需要生命元。

制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。

如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。

在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。

在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。

在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。

在每个小时的第40分：在有两个武士的城市，会发生战斗。

在每个小时的第50分，司令部报告它拥有的生命元数量。

在每个小时的第55分，每个武士报告其拥有的武器情况。

武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。

任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：

1) 武士降生

输出样例：000:00 blue dragon 1 born

表示在0点0分，编号为1的蓝魔dragon武士降生

如果造出的是lion，那么还要多输出一行，例:

000:00 blue lion 1 born

Its loyalty is 24

表示该lion降生时的忠诚度是24

2) lion逃跑

输出样例：000:05 blue lion 1 ran away

表示在0点5分，编号为1的蓝魔lion武士逃走

3) 武士前进到某一城市

输出样例：



000:10 red iceman 1 marched to city 1 with 20 elements and force 30

表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30

对于iceman,输出的生命值应该是变化后的数值

4) wolf抢敌人的武器

000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4

表示在0点35分，4号城市中，红魔1号武士wolf 抢走蓝魔2号武士dragon 3个bomb。为简单起见，武器不写复数形式

5) 报告战斗情况

战斗只有3种可能的输出结果：

000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements

表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20

000:40 both red iceman 1 and blue lion 12 died in city 2

注意，把红武士写前面

000:40 both red iceman 1 and blue lion 12 were alive in city 2

注意，把红武士写前面

6) 武士欢呼

输出样例：003:40 blue dragon 2 yelled in city 4

7) 武士抵达敌军司令部

输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30

（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值

8) 司令部被占领

输出样例：003:10 blue headquarter was taken

9)司令部报告生命元数量

000:50 100 elements in red headquarter

000:50 120 elements in blue headquarter

表示在0点50分，红方司令部有100个生命元，蓝方有120个

10)武士报告情况

000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements

为简单起见，武器都不写复数形式。elements一律写复数，哪怕只有1个

交代武器情况时，次序依次是：sword,bomb, arrow。

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 5 至 6 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

对于同一城市，同一时间发生的事情，先输出红方的，后输出蓝方的。

显然，8号事件发生之前的一瞬间一定发生了7号事件。输出时，这两件事算同一时间发生，但是应先输出7号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。



输入
第一行是t,代表测试数据组数

每组样例共三行。

第一行，4个整数 M,N,K, T。其含义为：
每个司令部一开始都有M个生命元( 1 <= M <= 100000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
lion每前进一步，忠诚度就降低K。(0<=K<=100)
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200
输出
对每组数据，先输出一行：

Case n:

如对第一组数据就输出 Case 1:

然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
样例输入
1
20 1 10 400
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:50 20 elements in red headquarter
000:50 10 elements in blue headquarter
000:55 blue lion 1 has 0 sword 1 bomb 0 arrow and 10 elements
001:05 blue lion 1 ran away
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
002:50 20 elements in red headquarter
002:50 10 elements in blue headquarter
003:50 20 elements in red headquarter
003:50 10 elements in blue headquarter
004:50 20 elements in red headquarter
004:50 10 elements in blue headquarter
005:50 20 elements in red headquarter
005:50 10 elements in blue headquarter
提示
请注意浮点数精度误差问题。OJ上的编译器编译出来的可执行程序，在这方面和你电脑上执行的程序很可能会不一致。5 * 0.3 的结果，有的机器上可能是 15.00000001，去尾取整得到15,有的机器上可能是14.9999999，去尾取整后就变成14。因此,本题不要写 5 * 0.3，要写 5 * 3 / 10。
来源
Guo Wei
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<string> red_warriors = {"iceman", "lion", "wolf", "ninja", "dragon"};
vector<string> blue_warriors = {"lion", "dragon", "ninja", "iceman", "wolf"};
vector<string> weapons = {"sword", "bomb", "arrow", "broken_arrow"};
int K;

class Warrior;

class Hq {
public:
    unordered_map<string, int> warrior_life;
    unordered_map<string, int> warrior_attack;

    bool stop;
    int heart;
    int iter;
    int time;
    string camp;
    vector<string> warriors;
    int total_num;
    int direction;

    Hq() {
        warrior_life = {
            {"iceman", 0}, {"lion", 0}, {"wolf", 0}, {"ninja", 0}, {"dragon", 0}
        };
        warrior_attack = {
            {"iceman", 0}, {"lion", 0}, {"wolf", 0}, {"ninja", 0}, {"dragon", 0}
        };
        heart = 0;
        iter = 0;
        stop = false;
        total_num = 0;
        direction = 0;
        time = 0;
    }

    void GetCamp(const string& str) {
        camp = str;
        if (camp == "red") {
            warriors = red_warriors;
            direction = 1;
        } else if (camp == "blue") {
            warriors = blue_warriors;
            direction = -1;
        }
    }
    void GetHeart(const int& num) { heart = num; }
    void GetLife(const int& num1, const int& num2, const int& num3, const int& num4, const int& num5) {
        warrior_life["iceman"] = num3;
        warrior_life["lion"] = num4;
        warrior_life["wolf"] = num5;
        warrior_life["ninja"] = num2;
        warrior_life["dragon"] = num1;
    }
    void GetAttack(const int& att1, const int& att2, const int& att3, const int& att4, const int& att5) {
        warrior_attack["iceman"] = att3;
        warrior_attack["lion"] = att4;
        warrior_attack["wolf"] = att5;
        warrior_attack["ninja"] = att2;
        warrior_attack["dragon"] = att1;
    }
    string GetHour() {
        string res = "";
        if (time < 10) res += "00";
        else if (time < 100) res += "0";
        res += to_string(time);
        return res;
    }

    void MakeWarrior();
    ~Hq();
};

unordered_map<string, Hq> hqs;

class Warrior {
public:
    string type;
    string camp;
    int id;
    int life;
    vector<string> weapon;
    int Hq_heart;
    int attack = 0;

    Warrior(const string& tp, const string& cp, const int& num, const int& lf, const int current_heart) {
        type = tp;
        camp = cp;
        id = num;
        life = lf;
        weapon = vector<string>();
        Hq_heart = current_heart;
        attack = hqs[camp].warrior_attack[type];
    }

    virtual void Weaponlize() {}
    virtual void Report() {}
    virtual ~Warrior() {}
};

class lion : public Warrior {
public:
    int loyalty;
    int betrayal;
    lion(const string& cp, const int& num, const int& lf, const int current_heart)
        : Warrior("lion", cp, num, lf, current_heart) {
        betrayal = K;
        loyalty = 0;
    }
    void Weaponlize() { 
        weapon.push_back(weapons[id % 3]);
        loyalty = Hq_heart; 
    }
    void Report() { cout << "Its loyalty is " << loyalty << endl; }
};

class ninja : public Warrior {
public:
    ninja(const string& cp, const int& num, const int& lf, const int current_heart)
        : Warrior("ninja", cp, num, lf, current_heart) {}
    void Weaponlize() {
        weapon.push_back(weapons[id % 3]);
        weapon.push_back(weapons[(id + 1) % 3]);
    }
    void Report() {}
};

class iceman : public Warrior {
public:
    iceman(const string& cp, const int& num, const int& lf, const int current_heart)
        : Warrior("iceman", cp, num, lf, current_heart) {}
    void Weaponlize() { weapon.push_back(weapons[id % 3]); }
    void Report() { }
};

class dragon : public Warrior {
public:
    double morale;
    dragon(const string& cp, const int& num, const int& lf, const int current_heart)
        : Warrior("dragon", cp, num, lf, current_heart) {
        morale = 0.0;
    }
    void Weaponlize() {
        weapon.push_back(weapons[id % 3]);
        morale = (double)Hq_heart / (double)life;
    }
    void Report() { }
};

class wolf : public Warrior {
public:
    wolf(const string& cp, const int& num, const int& lf, const int current_heart)
        : Warrior("wolf", cp, num, lf, current_heart) {}
    void Weaponlize() {}
    void Report() {}
};

vector<vector<Warrior*>> cities;

void Hq::MakeWarrior() {
    if (stop) return;

    string type;
    if (heart >= warrior_life[warriors[iter]]) {
        heart -= warrior_life[warriors[iter]];
        total_num++;

        type = warriors[iter];
        Warrior* new_warrior = nullptr;

        if (type == "lion") new_warrior = new lion(camp, total_num, warrior_life[type], heart);
        else if (type == "ninja") new_warrior = new ninja(camp, total_num, warrior_life[type], heart);
        else if (type == "iceman") new_warrior = new iceman(camp, total_num, warrior_life[type], heart);
        else if (type == "dragon") new_warrior = new dragon(camp, total_num, warrior_life[type], heart);
        else if (type == "wolf") new_warrior = new wolf(camp, total_num, warrior_life[type], heart);

        if (new_warrior) {
            new_warrior->Weaponlize();

            if(camp == "red") cities[0].push_back(new_warrior);
            else if(camp == "blue") cities[cities.size() - 1].push_back(new_warrior);

            cout << GetHour() << ":00" << " " << camp << " " << type << " "
                    << total_num << " born" << endl;
            new_warrior->Report();
        }
        iter = (iter + 1) % 5;
    } else stop = true;
}

Hq::~Hq() {
}

string timeprint(int hour, int minute) {
    string res = "";
    if (hour < 10) res += "00";
    else if (hour < 100) res += "0";
    res += to_string(hour);
    res += ":";
    if (minute < 10) res += "0";
    res += to_string(minute);
    return res;
}

int sort_weapon_value(const string& weapon) {
    if (weapon == "sword") return 0;
    else if (weapon == "bomb") return 1;
    else if (weapon == "broken_arrow") return 2;
    else if (weapon == "arrow") return 3;
    return -1;
}

void Sort_Weapons(Warrior* & warrior) {
    if (warrior->weapon.size() <= 1) return;
    if (warrior->weapon.size() >= 2) {
        sort(warrior->weapon.begin(), warrior->weapon.end(), [](const string& a, const string& b) {
            return sort_weapon_value(a) < sort_weapon_value(b);
        });
    }
}

string marching(vector<vector<Warrior*>>& cities, const int& city_num, int hour, int minute) {
    vector<vector<Warrior*>> update(city_num + 2, vector<Warrior*>());
    string result = "game_continue";

    for (int i = 0; i < city_num + 2; i++) {
        if (i == 0) {
            for (Warrior* & warrior : cities[1]) {
                if (warrior->camp == "blue") {
                    result = "blue_win";
                    if (warrior->type == "iceman") warrior->life -= warrior->life / 10;
                    cout << timeprint(hour, minute) << " " << warrior->camp << " " << warrior->type << " " << warrior->id
                         << " reached red headquarter with " << warrior->life << " elements and force " << warrior->attack << endl;
                    cout << timeprint(hour, minute) << " red headquarter was taken" << endl;
                    Sort_Weapons(warrior);
                }
            }
        } else if (i >= 1 && i <= city_num) {
            for (Warrior* & warrior : cities[i - 1]) {
                if (warrior->camp == "red") {
                    if (warrior->type == "iceman") warrior->life -= warrior->life / 10;
                    if (warrior->type == "lion") dynamic_cast<lion*>(warrior)->loyalty -= dynamic_cast<lion*>(warrior)->betrayal;
                    cout << timeprint(hour, minute) << " " << warrior->camp << " " << warrior->type << " " << warrior->id
                         << " marched to city " << i << " with " << warrior->life << " elements and force " << warrior->attack << endl;
                    update[i].push_back(warrior);
                    Sort_Weapons(warrior);
                }
            }

            for (Warrior* & warrior : cities[i + 1]) {
                if (warrior->camp == "blue") {
                    if (warrior->type == "iceman") warrior->life -= warrior->life / 10;
                    if (warrior->type == "lion") dynamic_cast<lion*>(warrior)->loyalty -= dynamic_cast<lion*>(warrior)->betrayal;
                    cout << timeprint(hour, minute) << " " << warrior->camp << " " << warrior->type << " " << warrior->id
                         << " marched to city " << i << " with " << warrior->life << " elements and force " << warrior->attack << endl;
                    update[i].push_back(warrior);
                    Sort_Weapons(warrior);
                }
            }
        } else if (i == city_num + 1) {
            for (Warrior* & warrior : cities[city_num]) {
                if (warrior->camp == "red") {
                    result = "red_win";
                    if (warrior->type == "iceman") warrior->life -= warrior->life / 10;
                    cout << timeprint(hour, minute) << " " << warrior->camp << " " << warrior->type << " " << warrior->id
                         << " reached blue headquarter with " << warrior->life << " elements and force " << warrior->attack << endl;
                    cout << timeprint(hour, minute) << " blue headquarter was taken" << endl;
                    Sort_Weapons(warrior);
                }
            }
        }
    }

    // 清理原cities中的指针（它们已经被移动到update中）
    for (auto& city : cities) {
        city.clear();  // 只清空vector，不delete（指针已转移）
    }
    
    cities = update;
    return result;
}


int give_weapon_value(const string& weapon) {
    if (weapon == "sword") return 0;
    else if (weapon == "bomb") return 1;
    else if (weapon == "arrow") return 2;
    else if (weapon == "broken_arrow") return 3;
    return -1;
}

void Stole_Weapons(Warrior* & warrior1, Warrior* & warrior2, int city_number, int hour, int minute) {
    if(warrior1->type != "wolf" && warrior2->type != "wolf") return;
    else if(warrior1->type == "wolf" && warrior2->type == "wolf") return;
    else if(warrior1->type == "wolf") {
        if(warrior2->weapon.empty()) return;
        if(warrior1->weapon.size() >= 10) return;
        if (warrior2->weapon.size() >= 2) {
            sort(warrior2->weapon.begin(), warrior2->weapon.end(), [](const string& a, const string& b) {
                return give_weapon_value(a) < give_weapon_value(b);
            });
        }
        string weapon_type = warrior2->weapon[0];
        int count = 0;
        while(!warrior2->weapon.empty() && (int)warrior1->weapon.size() < 10 && warrior2->weapon[0] == weapon_type) {
            warrior1->weapon.push_back(warrior2->weapon[0]);
            warrior2->weapon.erase(warrior2->weapon.begin());
            count ++;
        }
        Sort_Weapons(warrior1);
        Sort_Weapons(warrior2);
        if(weapon_type == "broken_arrow") weapon_type = "arrow";
        cout << timeprint(hour, minute) << " " << warrior1->camp << " wolf " << warrior1->id << " took "
             << count << " " << weapon_type << " from " << warrior2->camp << " " << warrior2->type
             << " " << warrior2->id << " in city " << city_number << endl;
    }
    else if(warrior2->type == "wolf") {
        if(warrior1->weapon.empty()) return;
        if(warrior2->weapon.size() >= 10) return;
        if (warrior1->weapon.size() >= 2) {
            sort(warrior1->weapon.begin(), warrior1->weapon.end(), [](const string& a, const string& b) {
                return give_weapon_value(a) < give_weapon_value(b);
            });
        }
        string weapon_type = warrior1->weapon[0];
        int count = 0;
        while(!warrior1->weapon.empty() && (int)warrior2->weapon.size() < 10 && warrior1->weapon[0] == weapon_type) {
            warrior2->weapon.push_back(warrior1->weapon[0]);
            warrior1->weapon.erase(warrior1->weapon.begin());
            count ++;
        }
        Sort_Weapons(warrior1);
        Sort_Weapons(warrior2);
        if(weapon_type == "broken_arrow") weapon_type = "arrow";
        cout << timeprint(hour, minute) << " " << warrior2->camp << " wolf " << warrior2->id << " took "
             << count << " " << weapon_type << " from " << warrior1->camp << " " << warrior1->type
             << " " << warrior1->id << " in city " << city_number << endl;
    }
}

void Take_Weapons(Warrior* & winner, Warrior* & loser) {
    if(winner->weapon.size() >= 10 || loser->weapon.empty()) return;
    if (loser->weapon.size() >= 2) {
        sort(loser->weapon.begin(), loser->weapon.end(), [](const string& a, const string& b) {
            return give_weapon_value(a) < give_weapon_value(b);
        });
    }
    while(!loser->weapon.empty() && (int)winner->weapon.size() < 10) {
        winner->weapon.push_back(loser->weapon[0]);
        loser->weapon.erase(loser->weapon.begin());
    }
}

bool Check_Attack_is_Zero(Warrior * warrior) {
    vector<string> weapon = warrior->weapon;
    for (const string& w : weapon) {
        if(w == "sword" && static_cast<int>(warrior->attack * 2 / 10) > 0) return false;
        else if(w == "bomb") return false;
        else if(w == "arrow") return false;
        else if(w == "broken_arrow") return false;
    }
    return true;
}


void Fight(vector<Warrior*>& city, int hour, int minute, int city_number) {
    if (city.size() != 2) return;
    
    bool red_first = (city_number % 2 == 1); // 奇数城市红先攻，偶数城市蓝先攻
    if ((red_first && city[0]->camp != "red") || (!red_first && city[0]->camp != "blue")) {
        swap(city[0], city[1]);
    }
    
    // 战斗！
    while (city[0]->life > 0 && city[1]->life > 0 && 
          (!city[0]->weapon.empty() || !city[1]->weapon.empty()) && 
          (!Check_Attack_is_Zero(city[0]) || !Check_Attack_is_Zero(city[1]))) {

        string weapon0 = city[0]->weapon.empty() ? "" : city[0]->weapon[0];
        string weapon1 = city[1]->weapon.empty() ? "" : city[1]->weapon[0];

        if (city[0]->life > 0 && !weapon0.empty()) { // 0先攻
            if (weapon0 == "sword") {
                city[1]->life -= static_cast<int>(city[0]->attack * 2 / 10);
                city[0]->weapon.erase(city[0]->weapon.begin());
                city[0]->weapon.push_back("sword");
            } else if (weapon0 == "bomb") {
                int attack_value = static_cast<int>(city[0]->attack * 4 / 10);
                int reflection_value = static_cast<int>(attack_value / 2);
                if (city[0]->type == "ninja") reflection_value = 0;
                city[1]->life -= attack_value;
                city[0]->life -= reflection_value;
                city[0]->weapon.erase(city[0]->weapon.begin());
            } else if (weapon0 == "broken_arrow") {
                city[1]->life -= static_cast<int>(city[0]->attack * 3 / 10);
                city[0]->weapon.erase(city[0]->weapon.begin());
            } else if (weapon0 == "arrow") {
                city[1]->life -= static_cast<int>(city[0]->attack * 3 / 10);
                city[0]->weapon.erase(city[0]->weapon.begin());
                city[0]->weapon.push_back("broken_arrow");
            }
        }

        if (city[1]->life > 0 && city[0]->life > 0 && !weapon1.empty()) { // 1后攻且0没有自杀
            if (weapon1 == "sword") {
                city[0]->life -= static_cast<int>(city[1]->attack * 2 / 10);
                city[1]->weapon.erase(city[1]->weapon.begin());
                city[1]->weapon.push_back("sword");
            } else if (weapon1 == "bomb") {
                int attack_value = static_cast<int>(city[1]->attack * 4 / 10);
                int reflection_value = static_cast<int>(attack_value / 2);
                if (city[1]->type == "ninja") reflection_value = 0;
                city[0]->life -= attack_value;
                city[1]->life -= reflection_value;
                city[1]->weapon.erase(city[1]->weapon.begin());
            } else if (weapon1 == "broken_arrow") {
                city[0]->life -= static_cast<int>(city[1]->attack * 3 / 10);
                city[1]->weapon.erase(city[1]->weapon.begin());
            } else if (weapon1 == "arrow") {
                city[0]->life -= static_cast<int>(city[1]->attack * 3 / 10);
                city[1]->weapon.erase(city[1]->weapon.begin());
                city[1]->weapon.push_back("broken_arrow");
            }
        }
    }

    // 夺取武器
    if (city[0]->life <= 0 && city[1]->life > 0) {
        // city[1]获胜，夺取city[0]的武器
        Take_Weapons(city[1], city[0]);
    } else if (city[1]->life <= 0 && city[0]->life > 0) {
        // city[0]获胜，夺取city[1]的武器
        Take_Weapons(city[0], city[1]);
    }

    // 报告战斗结果 该欢呼的欢呼 该死的死
    if (city[0]->life <= 0 && city[1]->life <= 0) {
        if(city[0]->camp == "red") {
            cout << timeprint(hour, minute) << " both " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
                 << " and " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
                 << " died in city " << city_number << endl;
        }
        else {
            cout << timeprint(hour, minute) << " both " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
                 << " and " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
                 << " died in city " << city_number << endl;
        }
        delete city[0];
        delete city[1];
        city.clear();
    } 
    
    else if (city[0]->life > 0 && city[1]->life > 0) {
        if(city[0]->camp == "blue") swap(city[0], city[1]);
        cout << timeprint(hour, minute) << " both " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
             << " and " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
             << " were alive in city " << city_number << endl;
        if (city[0]->type == "dragon") {
            cout << timeprint(hour, minute) << " " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
                 << " yelled in city " << city_number << endl;
        }
        if (city[1]->type == "dragon") {
            cout << timeprint(hour, minute) << " " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
                 << " yelled in city " << city_number << endl;
        }
        // 双方都存活，city保持不变
    } 
    
    else if (city[0]->life > 0 && city[1]->life <= 0) {
        cout << timeprint(hour, minute) << " " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
             << " killed " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
             << " in city " << city_number << " remaining " << city[0]->life << " elements" << endl;

        if (city[0]->type == "dragon") {
            cout << timeprint(hour, minute) << " " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
                 << " yelled in city " << city_number << endl;
        }
        delete city[1];
        city = {city[0]};
    } 
    
    else if (city[0]->life <= 0 && city[1]->life > 0) {
        cout << timeprint(hour, minute) << " " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
             << " killed " << city[0]->camp << " " << city[0]->type << " " << city[0]->id
             << " in city " << city_number << " remaining " << city[1]->life << " elements" << endl;

        if (city[1]->type == "dragon") {
            cout << timeprint(hour, minute) << " " << city[1]->camp << " " << city[1]->type << " " << city[1]->id
                 << " yelled in city " << city_number << endl;
        }
        delete city[0];
        city = {city[1]};
    }
}

void cleanupAllWarriors(vector<vector<Warrior*>>& cities) {
    for (auto& city : cities) {
        for (auto warrior : city) {
            delete warrior;
        }
        city.clear();
    }
    cities.clear();
}

int main() {
    int t, M, N, T;
    cin >> t;

    for (int i = 0; i < t; i++) {
        hqs.clear();  // 清空全局的 hqs
        cities.clear();

        cin >> M >> N >> K >> T;
        cout << "Case " << i + 1 << ":" << endl;

        int num1, num2, num3, num4, num5;
        cin >> num1 >> num2 >> num3 >> num4 >> num5;

        int att1, att2, att3, att4, att5;
        cin >> att1 >> att2 >> att3 >> att4 >> att5;

        // 创建并配置红方司令部
        Hq red;
        red.GetCamp("red");
        red.GetHeart(M);
        red.GetLife(num1, num2, num3, num4, num5);
        red.GetAttack(att1, att2, att3, att4, att5);
        hqs["red"] = red;  // 存入全局 map

        // 创建并配置蓝方司令部
        Hq blue;
        blue.GetCamp("blue");
        blue.GetHeart(M);
        blue.GetLife(num1, num2, num3, num4, num5);
        blue.GetAttack(att1, att2, att3, att4, att5);
        hqs["blue"] = blue;  // 存入全局 map

        cities = vector<vector<Warrior*>>(N + 2, vector<Warrior*>());

        int minute_limit = T % 60;
        int hour_limit = T / 60;
        int minute;

        for (int hour = 0; hour <= hour_limit; hour++) {
            minute = 0;
            if (!(hour == hour_limit && minute > minute_limit)) {
                // 直接使用 hqs 中的对象，不需要再设置 time（因为 MakeWarrior 内部会用到 time）
                // 但需要更新 time 成员
                hqs["red"].time = hour;
                hqs["blue"].time = hour;
                
                // 制造武士
                if (!hqs["red"].stop) hqs["red"].MakeWarrior();
                if (!hqs["blue"].stop) hqs["blue"].MakeWarrior();
            }

            minute = 5;
            if (!(hour == hour_limit && minute > minute_limit)) {
                // 处理 lion 逃跑
                for (auto & city : cities) {
                    for (auto it = city.begin(); it != city.end(); ) {
                        Warrior* warrior = *it;
                        if (warrior && warrior->type == "lion") {
                            lion* l = dynamic_cast<lion*>(warrior);
                            if (l && l->loyalty <= 0) {
                                cout << timeprint(hour, minute) << " " << warrior->camp 
                                     << " lion " << warrior->id << " ran away" << endl;
                                delete warrior;
                                it = city.erase(it);
                                continue;
                            }
                        }
                        ++it;
                    }
                }
            }

            minute = 10;
            string result = "game_continue";
            if (!(hour == hour_limit && minute > minute_limit)) {
                result = marching(cities, N, hour, minute);
            }
            if (result == "red_win" || result == "blue_win") break;

            minute = 35;
            if (!(hour == hour_limit && minute > minute_limit)) {
                for (int j = 0; j < (int)cities.size(); j++) {
                    auto & city = cities[j];
                    for(auto & warrior : city) { 
                        Sort_Weapons(warrior);
                    }
                    if(city.size() == 2) {
                        Stole_Weapons(city[0], city[1], j, hour, minute);
                    }
                }
            }

            minute = 40;
            if (!(hour == hour_limit && minute > minute_limit)) {
                for (int city_number = 0; city_number < (int)cities.size(); city_number++) {
                    vector<Warrior*>& city = cities[city_number];
                    if (city.size() == 2) {
                        Fight(city, hour, minute, city_number);
                    }
                }
            }

            minute = 50;
            if (!(hour == hour_limit && minute > minute_limit)) {
                // 报告生命元数量 - 直接使用 hqs 中的值
                cout << timeprint(hour, minute) << " " << hqs["red"].heart 
                     << " elements in red headquarter" << endl;
                cout << timeprint(hour, minute) << " " << hqs["blue"].heart 
                     << " elements in blue headquarter" << endl;
            }

            minute = 55;
            if (!(hour == hour_limit && minute > minute_limit)) {
                // 报告武器情况
                for(int j = 0; j < (int)cities.size(); j++) {
                    auto & city = cities[j];
                    if(city.size() == 2 && city[0]->camp == "blue") swap(city[0], city[1]);
                    for(auto & warrior : city) {
                        if(warrior->camp == "red") {
                            cout << timeprint(hour, minute) << " " << warrior->camp << " " 
                                 << warrior->type << " " << warrior->id << " has ";
                            int sword_count = 0, bomb_count = 0, arrow_count = 0;
                            for (const string& w : warrior->weapon) {
                                if (w == "sword") sword_count++;
                                else if (w == "bomb") bomb_count++;
                                else if (w == "arrow" || w == "broken_arrow") arrow_count++;
                            }
                            cout << sword_count << " sword " << bomb_count << " bomb "
                                 << arrow_count << " arrow and " << warrior->life << " elements" << endl;
                        }
                        if(warrior->camp == "blue") {
                            cout << timeprint(hour, minute) << " " << warrior->camp << " " 
                                 << warrior->type << " " << warrior->id << " has ";
                            int sword_count = 0, bomb_count = 0, arrow_count = 0;
                            for (const string& w : warrior->weapon) {
                                if (w == "sword") sword_count++;
                                else if (w == "bomb") bomb_count++;
                                else if (w == "arrow" || w == "broken_arrow") arrow_count++;
                            }
                            cout << sword_count << " sword " << bomb_count << " bomb "
                                 << arrow_count << " arrow and " << warrior->life << " elements" << endl;
                        }
                    }
                }
            }
        }

        cleanupAllWarriors(cities);
        hqs.clear();
    }

    return 0;
}