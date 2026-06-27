/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20 )。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。每次战斗只有一方发起主动进攻一次。被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。

如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。

如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。注意，司令部总是先完成全部奖励工作，然后才开始从各个打了胜仗的城市回收生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。

如果一次战斗的结果是双方都幸存(平局)，则双方都不能拿走发生战斗的城市的生命元。

城市可以插旗子，一开始所有城市都没有旗子。在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。

当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗之间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的；但如果中间有平局的战斗，就不算连续了) ，那么该城市就会插上胜方的旗帜，若原来插着败方的旗帜，则败方旗帜落下。旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。

各种武器有其特点：

sword武器的初始攻击力为拥有它的武士的攻击力的20%（去尾取整）。但是sword每经过一次战斗(不论是主动攻击还是反击)，就会变钝，攻击力变为本次战斗前的80% (去尾取整)。sword攻击力变为0时，视为武士失去了sword。如果武士降生时得到了一个初始攻击力为0的sword，则视为武士没有sword.

arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人（不能攻击对方司令部里的敌人）而不被还击。arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。

拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。

武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。

不同的武士有不同的特点。

dragon可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。士气增减发生在欢呼之前。

ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。ninja 挨打了也从不反击敌人。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。

lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每经过一场未能杀死敌人的战斗，忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。Lion在己方司令部可能逃跑。lion 若是战死，则其战斗前的生命值就会转移到对手身上。所谓“战斗前”，就是每个小时的40分前的一瞬间。

wolf降生时没有武器，但是在战斗中如果获胜（杀死敌人），就会缴获敌人的武器，但自己已有的武器就不缴获了。被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。

以下是不同时间会发生的不同事件：

在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。

在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。

在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。

在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。

在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。

在每个小时的第35分，拥有arrow的武士放箭，对敌人造成伤害。放箭事件应算发生在箭发出的城市。注意，放箭不算是战斗，因此放箭的武士不会得到任何好处。武士在没有敌人的城市被箭射死也不影响其所在城市的旗帜更换情况。

在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。

在每个小时的第40分：在有两个武士的城市，会发生战斗。 如果敌人在5分钟前已经被飞来的arrow射死，那么仍然视为发生了一场战斗，而且存活者视为获得了战斗的胜利。此情况下不会有“武士主动攻击”，“武士反击”，“武士战死”的事件发生，但战斗胜利后应该发生的事情都会发生。如Wolf一样能缴获武器，旗帜也可能更换，等等。在此情况下,Dragon同样会通过判断是否应该轮到自己主动攻击来决定是否欢呼。

在每个小时的第50分，司令部报告它拥有的生命元数量。

在每个小时的第55分，每个武士报告其拥有的武器情况。

武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。

任何一方的司令部里若是出现了2个敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：



1) 武士降生
输出样例： 000:00 blue lion 1 born

表示在 0点0分，编号为1的蓝魔lion武士降生
如果造出的是dragon，那么还要多输出一行，例：

000:00 blue dragon 1 born
Its morale is 23.34

表示该该dragon降生时士气是23. 34(四舍五入到小数点后两位)

如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24

表示该lion降生时的忠诚度是24

2) lion逃跑
输出样例： 000:05 blue lion 1 ran away
表示在 0点5分，编号为1的蓝魔lion武士逃走

3) 武士前进到某一城市
输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
表示在 0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
对于iceman,输出的生命值和攻击力应该是变化后的数值

4)武士放箭
输出样例： 000:35 blue dragon 1 shot
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭。如果射出的箭杀死了敌人，则应如下输出：
000:35 blue dragon 1 shot and killed red lion 4
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭，杀死了编号为4的红魔lion。

5)武士使用bomb
输出样例： 000:38 blue dragon 1 used a bomb and killed red lion 7
表示在 0点38分，编号为1的蓝魔dragon武士用炸弹和编号为7的红魔lion同归于尽。

6) 武士主动进攻
输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30

7) 武士反击
输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1
表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion

8) 武士战死
输出样例：001:40 red lion 2 was killed in city 1
被箭射死的武士就不会有这一条输出。

9) 武士欢呼
输出样例：003:40 blue dragon 2 yelled in city 4

10) 武士获取生命元( elements )
输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter

输出不包括在30分不是通过战斗获取的elements

11) 旗帜升起
输出样例：004:40 blue flag raised in city 4

12) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
(此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值

13) 司令部被占领
输出样例：003:10 blue headquarter was taken

14)司令部报告生命元数量
000:50 100 elements in red headquarter
000:50 120 elements in blue headquarter
表示在0点50分，红方司令部有100个生命元，蓝方有120个

15)武士报告武器情况
000:55 blue wolf 2 has arrow(2),bomb,sword(23)
000:55 blue wolf 4 has no weapon
000:55 blue wolf 5 has sword(20)
表示在0点55分，蓝魔2号武士wolf有一支arrow（这支arrow还可以用2次），一个bomb，还有一支攻击力为23的sword。
蓝魔4号武士wolf没武器。
蓝魔5号武士wolf有一支攻击力为20的sword。
交代武器情况时，次序依次是：arrow,bomb,sword。如果没有某种武器，某种武器就不用提。报告时，先按从西向东的顺序所有的红武士报告，然后再从西向东所有的蓝武士报告。

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 6 至 11 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

显然，13号事件发生之前的一瞬间一定发生了12号事件。输出时，这两件事算同一时间发生，但是应先输出12号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。

输入
第一行是t,代表测试数据组数
每组样例共三行。
第一行，五个整数 M,N,R,K, T。其含义为：

每个司令部一开始都有M个生命元( 1 <= M <= 10000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
arrow的攻击力是R
lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000

输出
对每组数据，先输出一行：
Case n:
如对第一组数据就输出 Case1:
然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。

样例输入
1
20 1 10 10 1000
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:30 blue lion 1 earned 10 elements for his headquarter
000:50 20 elements in red headquarter
000:50 20 elements in blue headquarter
000:55 blue lion 1 has no weapon
001:00 blue dragon 2 born
Its morale is 0.00
001:10 blue lion 1 reached red headquarter with 10 elements and force 5
001:10 blue dragon 2 marched to city 1 with 20 elements and force 5
001:30 blue dragon 2 earned 10 elements for his headquarter
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
001:55 blue lion 1 has no weapon
001:55 blue dragon 2 has arrow(3)
002:10 blue dragon 2 reached red headquarter with 20 elements and force 5
002:10 red headquarter was taken
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum Camp {
    RED = 0,
    BLUE = 1
};

enum WarriorType {
    DRAGON = 0,
    NINJA = 1,
    ICEMAN = 2,
    LION = 3,
    WOLF = 4
};

struct WeaponState {
    int sword = 0;
    bool bomb = false;
    int arrow = 0;
};

struct Warrior {
    int id = 0;
    Camp camp = RED;
    WarriorType type = DRAGON;
    int hp = 0;
    int atk = 0;
    int pos = -1;

    bool dead = false;
    bool reached_enemy_hq = false;
    int death_minute = -1;

    int iceman_steps = 0;
    int loyalty = 0;
    double morale = 0.0;

    WeaponState weapon;
};

struct Headquarter {
    Camp camp = RED;
    int elements = 0;
    int next_idx = 0;
    int total_born = 0;
};

struct CityState {
    int elements = 0;
    int flag = 0;       // 0 none, 1 red, 2 blue
    int last_winner = 0; // 0 none, 1 red, 2 blue
};

struct BattleInfo {
    vector<string> logs_6_to_9;
    bool winner_exists = false;
    Camp winner_camp = RED;
    Warrior* winner = nullptr;
    bool winner_killed_enemy = false;
    bool flag_raised = false;
    Camp raised_flag_camp = RED;
    bool battle_happened = false;
};

static const string CAMP_NAME[2] = {"red", "blue"};
static const string TYPE_NAME[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};

class Game {
public:
    int M = 0;
    int N = 0;
    int R = 0;
    int K = 0;
    int T = 0;

    int life_cost[5] = {0};
    int attack_val[5] = {0};

    Headquarter hq_red;
    Headquarter hq_blue;
    vector<CityState> city; // 0..N+1, use 1..N for city states

    vector<unique_ptr<Warrior>> all_warriors;

    bool war_end = false;

    Game(int m, int n, int r, int k, int t,
         const int life_in[5], const int attack_in[5]) {
        M = m;
        N = n;
        R = r;
        K = k;
        T = t;
        for (int i = 0; i < 5; ++i) {
            life_cost[i] = life_in[i];
            attack_val[i] = attack_in[i];
        }

        hq_red.camp = RED;
        hq_red.elements = M;
        hq_red.next_idx = 0;
        hq_red.total_born = 0;

        hq_blue.camp = BLUE;
        hq_blue.elements = M;
        hq_blue.next_idx = 0;
        hq_blue.total_born = 0;

        city.assign(N + 2, CityState());
    }

    string time_str(int total_minute) const {
        int hh = total_minute / 60;
        int mm = total_minute % 60;
        ostringstream oss;
        oss << setfill('0') << setw(3) << hh << ":" << setw(2) << mm;
        return oss.str();
    }

    static Camp enemy(Camp c) {
        return c == RED ? BLUE : RED;
    }

    int camp_to_mark(Camp c) const {
        return c == RED ? 1 : 2;
    }

    bool is_enemy_hq_pos(const Warrior* w) const {
        if (w->camp == RED) return w->pos == N + 1;
        return w->pos == 0;
    }

    int sword_damage(const Warrior* w) const {
        return w->weapon.sword;
    }

    void decay_sword(Warrior* w) {
        if (w->weapon.sword <= 0) return;
        w->weapon.sword = (w->weapon.sword * 8) / 10;
        if (w->weapon.sword <= 0) w->weapon.sword = 0;
    }

    vector<Warrior*> warriors_at_pos(int pos, bool include_dead) {
        vector<Warrior*> res;
        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->pos != pos) continue;
            if (!include_dead && w->dead) continue;
            res.push_back(w);
        }
        sort(res.begin(), res.end(), [](Warrior* a, Warrior* b) {
            if (a->camp != b->camp) return a->camp < b->camp;
            return a->id < b->id;
        });
        return res;
    }

    Warrior* get_one(vector<Warrior*>& arr, Camp camp, bool alive_only) {
        for (Warrior* w : arr) {
            if (w->camp != camp) continue;
            if (alive_only && w->dead) continue;
            return w;
        }
        return nullptr;
    }

    bool has_any_weapon(const Warrior* w) const {
        return w->weapon.arrow > 0 || w->weapon.bomb || w->weapon.sword > 0;
    }

    string weapon_report(const Warrior* w) const {
        if (!has_any_weapon(w)) return "no weapon";
        vector<string> parts;
        if (w->weapon.arrow > 0) {
            parts.push_back("arrow(" + to_string(w->weapon.arrow) + ")");
        }
        if (w->weapon.bomb) {
            parts.push_back("bomb");
        }
        if (w->weapon.sword > 0) {
            parts.push_back("sword(" + to_string(w->weapon.sword) + ")");
        }
        string out;
        for (int i = 0; i < (int)parts.size(); ++i) {
            if (i) out += ",";
            out += parts[i];
        }
        return out;
    }

    void give_birth(int now_minute) {
        static const WarriorType red_order[5] = {ICEMAN, LION, WOLF, NINJA, DRAGON};
        static const WarriorType blue_order[5] = {LION, DRAGON, NINJA, ICEMAN, WOLF};

        auto create_one = [&](Headquarter& hq, const WarriorType order_arr[5]) {
            WarriorType tp = order_arr[hq.next_idx];
            int need = life_cost[tp];
            if (hq.elements < need) return;

            hq.elements -= need;
            hq.total_born++;

            auto w = make_unique<Warrior>();
            w->id = hq.total_born;
            w->camp = hq.camp;
            w->type = tp;
            w->hp = life_cost[tp];
            w->atk = attack_val[tp];
            w->pos = (hq.camp == RED ? 0 : N + 1);

            int weapon_idx = w->id % 3;
            auto give_weapon_by_idx = [&](int idx) {
                if (idx == 0) {
                    int s = w->atk / 5;
                    if (s > 0) w->weapon.sword = s;
                } else if (idx == 1) {
                    w->weapon.bomb = true;
                } else {
                    w->weapon.arrow = 3;
                }
            };

            if (tp == DRAGON) {
                give_weapon_by_idx(weapon_idx);
                w->morale = static_cast<double>(hq.elements) / static_cast<double>(life_cost[DRAGON]);
            } else if (tp == NINJA) {
                give_weapon_by_idx(weapon_idx);
                give_weapon_by_idx((w->id + 1) % 3);
            } else if (tp == ICEMAN) {
                give_weapon_by_idx(weapon_idx);
            } else if (tp == LION) {
                w->loyalty = hq.elements;
            }

            cout << time_str(now_minute) << " " << CAMP_NAME[w->camp] << " "
                 << TYPE_NAME[w->type] << " " << w->id << " born" << "\n";

            if (tp == DRAGON) {
                cout << "Its morale is " << fixed << setprecision(2) << w->morale << "\n";
                cout.unsetf(ios::floatfield);
            } else if (tp == LION) {
                cout << "Its loyalty is " << w->loyalty << "\n";
            }

            all_warriors.push_back(std::move(w));
            hq.next_idx = (hq.next_idx + 1) % 5;
        };

        create_one(hq_red, red_order);
        create_one(hq_blue, blue_order);
    }

    void lion_runaway(int now_minute) {
        vector<Warrior*> run;
        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->dead) continue;
            if (w->type != LION) continue;
            if (w->loyalty > 0) continue;
            if (is_enemy_hq_pos(w)) continue;
            run.push_back(w);
        }
        sort(run.begin(), run.end(), [](Warrior* a, Warrior* b) {
            if (a->pos != b->pos) return a->pos < b->pos;
            if (a->camp != b->camp) return a->camp < b->camp;
            return a->id < b->id;
        });

        for (Warrior* w : run) {
            if (w->dead) continue;
            cout << time_str(now_minute) << " " << CAMP_NAME[w->camp] << " lion "
                 << w->id << " ran away" << "\n";
            w->dead = true;
            w->death_minute = now_minute;
            w->pos = -1;
        }
    }

    void iceman_after_move(Warrior* w) {
        if (w->type != ICEMAN) return;
        w->iceman_steps++;
        if (w->iceman_steps % 2 == 0) {
            if (w->hp > 9) w->hp -= 9;
            else w->hp = 1;
            w->atk += 20;
        }
    }

    void march(int now_minute) {
        vector<Warrior*> red_arrive(N + 2, nullptr);
        vector<Warrior*> blue_arrive(N + 2, nullptr);

        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->dead) continue;
            if (w->reached_enemy_hq) continue;

            if (w->camp == RED) {
                w->pos++;
                iceman_after_move(w);
                red_arrive[w->pos] = w;
                if (w->pos == N + 1) w->reached_enemy_hq = true;
            } else {
                w->pos--;
                iceman_after_move(w);
                blue_arrive[w->pos] = w;
                if (w->pos == 0) w->reached_enemy_hq = true;
            }
        }

        int blue_in_red_hq = 0;
        int red_in_blue_hq = 0;
        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->dead) continue;
            if (w->camp == BLUE && w->pos == 0) blue_in_red_hq++;
            if (w->camp == RED && w->pos == N + 1) red_in_blue_hq++;
        }

        bool red_hq_taken = (blue_in_red_hq >= 2);
        bool blue_hq_taken = (red_in_blue_hq >= 2);

        if (blue_arrive[0]) {
            Warrior* w = blue_arrive[0];
            cout << time_str(now_minute) << " " << CAMP_NAME[w->camp] << " "
                 << TYPE_NAME[w->type] << " " << w->id
                 << " reached red headquarter with " << w->hp
                 << " elements and force " << w->atk << "\n";

            if (red_hq_taken) {
                cout << time_str(now_minute) << " red headquarter was taken" << "\n";
            }
        }

        for (int i = 1; i <= N; ++i) {
            if (red_arrive[i]) {
                Warrior* w = red_arrive[i];
                cout << time_str(now_minute) << " " << CAMP_NAME[w->camp] << " "
                     << TYPE_NAME[w->type] << " " << w->id << " marched to city "
                     << i << " with " << w->hp << " elements and force "
                     << w->atk << "\n";
            }
            if (blue_arrive[i]) {
                Warrior* w = blue_arrive[i];
                cout << time_str(now_minute) << " " << CAMP_NAME[w->camp] << " "
                     << TYPE_NAME[w->type] << " " << w->id << " marched to city "
                     << i << " with " << w->hp << " elements and force "
                     << w->atk << "\n";
            }
        }

        if (red_arrive[N + 1]) {
            Warrior* w = red_arrive[N + 1];
            cout << time_str(now_minute) << " " << CAMP_NAME[w->camp] << " "
                 << TYPE_NAME[w->type] << " " << w->id
                 << " reached blue headquarter with " << w->hp
                 << " elements and force " << w->atk << "\n";

            if (blue_hq_taken) {
                cout << time_str(now_minute) << " blue headquarter was taken" << "\n";
            }
        }

        if (red_hq_taken || blue_hq_taken) war_end = true;
    }

    void city_produce_elements() {
        for (int i = 1; i <= N; ++i) {
            city[i].elements += 10;
        }
    }

    void city_take_elements_30(int now_minute) {
        for (int i = 1; i <= N; ++i) {
            vector<Warrior*> ws = warriors_at_pos(i, false);
            Warrior* red = get_one(ws, RED, true);
            Warrior* blue = get_one(ws, BLUE, true);
            if ((red == nullptr) == (blue == nullptr)) continue;

            Warrior* winner = red ? red : blue;
            if (city[i].elements <= 0) continue;

            int gain = city[i].elements;
            city[i].elements = 0;
            if (winner->camp == RED) hq_red.elements += gain;
            else hq_blue.elements += gain;

            cout << time_str(now_minute) << " " << CAMP_NAME[winner->camp] << " "
                 << TYPE_NAME[winner->type] << " " << winner->id
                 << " earned " << gain << " elements for his headquarter" << "\n";
        }
    }

    void arrow_shot_35(int now_minute) {
        struct Shot {
            Warrior* shooter = nullptr;
            Warrior* target = nullptr;
            int shooter_pos = -1;
        };

        vector<Shot> shots;
        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->dead) continue;
            if (w->reached_enemy_hq) continue;
            if (w->weapon.arrow <= 0) continue;

            int target_pos = -1;
            if (w->camp == RED) {
                if (w->pos + 1 <= N) target_pos = w->pos + 1;
            } else {
                if (w->pos - 1 >= 1) target_pos = w->pos - 1;
            }
            if (target_pos < 0) continue;

            vector<Warrior*> ws = warriors_at_pos(target_pos, false);
            Warrior* enemy_w = get_one(ws, enemy(w->camp), true);
            if (!enemy_w) continue;

            Shot st;
            st.shooter = w;
            st.target = enemy_w;
            st.shooter_pos = w->pos;
            shots.push_back(st);
        }

        sort(shots.begin(), shots.end(), [](const Shot& a, const Shot& b) {
            if (a.shooter_pos != b.shooter_pos) return a.shooter_pos < b.shooter_pos;
            if (a.shooter->camp != b.shooter->camp) return a.shooter->camp < b.shooter->camp;
            return a.shooter->id < b.shooter->id;
        });

        for (const Shot& st : shots) {
            if (st.shooter->weapon.arrow > 0) {
                st.shooter->weapon.arrow--;
            }
            st.target->hp -= R;
            if (st.target->hp <= 0) {
                st.target->hp = 0;
                st.target->dead = true;
                st.target->death_minute = now_minute;
            }
        }

        for (const Shot& st : shots) {
            bool killed = st.target->dead && st.target->death_minute == now_minute;
            cout << time_str(now_minute) << " " << CAMP_NAME[st.shooter->camp] << " "
                 << TYPE_NAME[st.shooter->type] << " " << st.shooter->id << " shot";
            if (killed) {
                cout << " and killed " << CAMP_NAME[st.target->camp] << " "
                     << TYPE_NAME[st.target->type] << " " << st.target->id;
            }
            cout << "\n";
        }
    }

    Camp attacker_camp_of_city(int city_id) const {
        if (city[city_id].flag == 1) return RED;
        if (city[city_id].flag == 2) return BLUE;
        return (city_id % 2 == 1) ? RED : BLUE;
    }

    bool should_use_bomb(Warrior* self, Warrior* enemy_w, bool self_is_attacker) {
        if (!self || !enemy_w) return false;
        if (self->dead || enemy_w->dead) return false;
        if (!self->weapon.bomb) return false;

        if (self_is_attacker) {
            int dmg = self->atk + sword_damage(self);
            int enemy_hp_after = enemy_w->hp - dmg;
            if (enemy_hp_after <= 0) return false;
            if (enemy_w->type == NINJA) return false;
            int fb = enemy_w->atk / 2 + sword_damage(enemy_w);
            int self_hp_after = self->hp - fb;
            return self_hp_after <= 0;
        }

        int dmg = enemy_w->atk + sword_damage(enemy_w);
        int self_hp_after = self->hp - dmg;
        return self_hp_after <= 0;
    }

    void bomb_38(int now_minute) {
        for (int i = 1; i <= N; ++i) {
            vector<Warrior*> ws = warriors_at_pos(i, false);
            Warrior* red = get_one(ws, RED, true);
            Warrior* blue = get_one(ws, BLUE, true);
            if (!red || !blue) continue;

            Camp atk_camp = attacker_camp_of_city(i);
            Warrior* atk = (atk_camp == RED ? red : blue);
            Warrior* def = (atk_camp == RED ? blue : red);

            Warrior* user = nullptr;
            Warrior* victim = nullptr;

            if (should_use_bomb(atk, def, true)) {
                user = atk;
                victim = def;
            } else if (should_use_bomb(def, atk, false)) {
                user = def;
                victim = atk;
            }

            if (user) {
                cout << time_str(now_minute) << " " << CAMP_NAME[user->camp] << " "
                     << TYPE_NAME[user->type] << " " << user->id
                     << " used a bomb and killed " << CAMP_NAME[victim->camp] << " "
                     << TYPE_NAME[victim->type] << " " << victim->id << "\n";

                user->weapon.bomb = false;
                user->dead = true;
                user->death_minute = now_minute;
                user->pos = -1;

                victim->dead = true;
                victim->death_minute = now_minute;
                victim->pos = -1;
            }
        }
    }

    void wolf_take_weapon(Warrior* winner, Warrior* loser) {
        if (!winner || !loser) return;
        if (winner->type != WOLF) return;

        if (winner->weapon.arrow == 0 && loser->weapon.arrow > 0) {
            winner->weapon.arrow = loser->weapon.arrow;
        }
        if (!winner->weapon.bomb && loser->weapon.bomb) {
            winner->weapon.bomb = true;
        }
        if (winner->weapon.sword == 0 && loser->weapon.sword > 0) {
            winner->weapon.sword = loser->weapon.sword;
        }
    }

    void mark_death(Warrior* w, int now_minute) {
        if (!w) return;
        w->dead = true;
        w->death_minute = now_minute;
        w->hp = 0;
    }

    void finalize_dead_after_battle() {
        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->dead && w->pos >= 0) {
                w->pos = -1;
            }
        }
    }

    vector<BattleInfo> battle_40_collect(int now_minute,
                                         vector<pair<int, Warrior*>>& red_reward,
                                         vector<pair<int, Warrior*>>& blue_reward) {
        vector<BattleInfo> info(N + 2);

        for (int i = 1; i <= N; ++i) {
            BattleInfo bi;

            vector<Warrior*> ws_all = warriors_at_pos(i, true);
            Warrior* red_all = get_one(ws_all, RED, false);
            Warrior* blue_all = get_one(ws_all, BLUE, false);

            if (!red_all || !blue_all) {
                info[i] = bi;
                continue;
            }

            Warrior* red = red_all;
            Warrior* blue = blue_all;

            Camp atk_camp = attacker_camp_of_city(i);
            Warrior* atk = (atk_camp == RED ? red : blue);
            Warrior* def = (atk_camp == RED ? blue : red);

            bool atk_alive = !atk->dead;
            bool def_alive = !def->dead;

            if (!atk_alive && !def_alive) {
                info[i] = bi;
                continue;
            }

            bi.battle_happened = true;

            int red_pre_hp = red->hp;
            int blue_pre_hp = blue->hp;

            bool kill_by_attack = false;
            bool kill_by_fight_back = false;

            if (atk_alive && def_alive) {
                {
                    ostringstream oss;
                    oss << time_str(now_minute) << " " << CAMP_NAME[atk->camp] << " "
                        << TYPE_NAME[atk->type] << " " << atk->id << " attacked "
                        << CAMP_NAME[def->camp] << " " << TYPE_NAME[def->type] << " "
                        << def->id << " in city " << i << " with " << atk->hp
                        << " elements and force " << atk->atk;
                    bi.logs_6_to_9.push_back(oss.str());
                }

                int damage = atk->atk + sword_damage(atk);
                def->hp -= damage;
                decay_sword(atk);

                if (def->hp <= 0) {
                    mark_death(def, now_minute);
                    kill_by_attack = true;
                } else if (def->type != NINJA) {
                    {
                        ostringstream oss;
                        oss << time_str(now_minute) << " " << CAMP_NAME[def->camp] << " "
                            << TYPE_NAME[def->type] << " " << def->id
                            << " fought back against " << CAMP_NAME[atk->camp] << " "
                            << TYPE_NAME[atk->type] << " " << atk->id
                            << " in city " << i;
                        bi.logs_6_to_9.push_back(oss.str());
                    }

                    int fb = def->atk / 2 + sword_damage(def);
                    atk->hp -= fb;
                    decay_sword(def);
                    if (atk->hp <= 0) {
                        mark_death(atk, now_minute);
                        kill_by_fight_back = true;
                    }
                }
            }

            Warrior* winner = nullptr;
            Warrior* loser = nullptr;

            if (!red->dead && blue->dead) {
                winner = red;
                loser = blue;
            } else if (red->dead && !blue->dead) {
                winner = blue;
                loser = red;
            }

            if (kill_by_attack) {
                ostringstream oss;
                oss << time_str(now_minute) << " " << CAMP_NAME[def->camp] << " "
                    << TYPE_NAME[def->type] << " " << def->id
                    << " was killed in city " << i;
                bi.logs_6_to_9.push_back(oss.str());
            }
            if (kill_by_fight_back) {
                ostringstream oss;
                oss << time_str(now_minute) << " " << CAMP_NAME[atk->camp] << " "
                    << TYPE_NAME[atk->type] << " " << atk->id
                    << " was killed in city " << i;
                bi.logs_6_to_9.push_back(oss.str());
            }

            if (winner) {
                bi.winner_exists = true;
                bi.winner = winner;
                bi.winner_camp = winner->camp;
                bi.winner_killed_enemy = true;

                if (loser->type == LION && loser->death_minute == now_minute) {
                    int transfer_hp = (loser->camp == RED ? red_pre_hp : blue_pre_hp);
                    if (loser == red) transfer_hp = red_pre_hp;
                    if (loser == blue) transfer_hp = blue_pre_hp;
                    winner->hp += transfer_hp;
                }

                wolf_take_weapon(winner, loser);

                if (winner->type == DRAGON) {
                    winner->morale += 0.2;
                }

                if (winner->type == LION) {
                    // no loyalty decrease for winner lion who killed enemy
                }
                if (loser->type == LION && !loser->dead) {
                    loser->loyalty -= K;
                }

                if (atk->type == DRAGON && !atk->dead && atk->morale > 0.8) {
                    ostringstream oss;
                    oss << time_str(now_minute) << " " << CAMP_NAME[atk->camp] << " dragon "
                        << atk->id << " yelled in city " << i;
                    bi.logs_6_to_9.push_back(oss.str());
                }

                int mark = camp_to_mark(winner->camp);
                if (city[i].last_winner == mark && city[i].flag != mark) {
                    city[i].flag = mark;
                    bi.flag_raised = true;
                    bi.raised_flag_camp = winner->camp;
                }
                city[i].last_winner = mark;

                if (winner->camp == RED) red_reward.push_back({i, winner});
                else blue_reward.push_back({i, winner});
            } else {
                // tie (both alive) or both dead before battle; only tie should reset streak.
                if (!red->dead && !blue->dead) {
                    city[i].last_winner = 0;

                    if (red->type == DRAGON) red->morale -= 0.2;
                    if (blue->type == DRAGON) blue->morale -= 0.2;

                    if (red->type == LION) red->loyalty -= K;
                    if (blue->type == LION) blue->loyalty -= K;

                    if (atk->type == DRAGON && !atk->dead && atk->morale > 0.8) {
                        ostringstream oss;
                        oss << time_str(now_minute) << " " << CAMP_NAME[atk->camp]
                            << " dragon " << atk->id << " yelled in city " << i;
                        bi.logs_6_to_9.push_back(oss.str());
                    }
                }
            }

            info[i] = bi;
        }

        return info;
    }

    void reward_winners(vector<pair<int, Warrior*>>& red_reward,
                        vector<pair<int, Warrior*>>& blue_reward) {
        sort(red_reward.begin(), red_reward.end(), [](const pair<int, Warrior*>& a,
                                                      const pair<int, Warrior*>& b) {
            return a.first > b.first;
        });
        sort(blue_reward.begin(), blue_reward.end(), [](const pair<int, Warrior*>& a,
                                                        const pair<int, Warrior*>& b) {
            return a.first < b.first;
        });

        for (auto& p : red_reward) {
            Warrior* w = p.second;
            if (!w || w->dead) continue;
            if (hq_red.elements >= 8) {
                hq_red.elements -= 8;
                w->hp += 8;
            }
        }

        for (auto& p : blue_reward) {
            Warrior* w = p.second;
            if (!w || w->dead) continue;
            if (hq_blue.elements >= 8) {
                hq_blue.elements -= 8;
                w->hp += 8;
            }
        }
    }

    void print_battle_tail_40(int now_minute, const vector<BattleInfo>& info) {
        for (int i = 1; i <= N; ++i) {
            for (const string& s : info[i].logs_6_to_9) {
                cout << s << "\n";
            }

            if (info[i].winner_exists && info[i].winner && !info[i].winner->dead) {
                if (city[i].elements > 0 && info[i].winner_killed_enemy) {
                    int gain = city[i].elements;
                    city[i].elements = 0;
                    if (info[i].winner->camp == RED) hq_red.elements += gain;
                    else hq_blue.elements += gain;

                    cout << time_str(now_minute) << " "
                         << CAMP_NAME[info[i].winner->camp] << " "
                         << TYPE_NAME[info[i].winner->type] << " "
                         << info[i].winner->id << " earned " << gain
                         << " elements for his headquarter" << "\n";
                }
            }

            if (info[i].flag_raised) {
                cout << time_str(now_minute) << " " << CAMP_NAME[info[i].raised_flag_camp]
                     << " flag raised in city " << i << "\n";
            }
        }
    }

    void battle_40(int now_minute) {
        vector<pair<int, Warrior*>> red_reward;
        vector<pair<int, Warrior*>> blue_reward;

        vector<BattleInfo> info = battle_40_collect(now_minute, red_reward, blue_reward);
        reward_winners(red_reward, blue_reward);
        print_battle_tail_40(now_minute, info);
        finalize_dead_after_battle();
    }

    void report_hq_50(int now_minute) const {
        cout << time_str(now_minute) << " " << hq_red.elements << " elements in red headquarter" << "\n";
        cout << time_str(now_minute) << " " << hq_blue.elements << " elements in blue headquarter" << "\n";
    }

    void report_weapon_55(int now_minute) {
        vector<Warrior*> red_list;
        vector<Warrior*> blue_list;

        for (auto& up : all_warriors) {
            Warrior* w = up.get();
            if (w->dead) continue;
            if (w->camp == RED) red_list.push_back(w);
            else blue_list.push_back(w);
        }

        auto cmp_pos = [](Warrior* a, Warrior* b) {
            if (a->pos != b->pos) return a->pos < b->pos;
            return a->id < b->id;
        };
        sort(red_list.begin(), red_list.end(), cmp_pos);
        sort(blue_list.begin(), blue_list.end(), cmp_pos);

        for (Warrior* w : red_list) {
            cout << time_str(now_minute) << " red " << TYPE_NAME[w->type] << " "
                 << w->id << " has " << weapon_report(w) << "\n";
        }
        for (Warrior* w : blue_list) {
            cout << time_str(now_minute) << " blue " << TYPE_NAME[w->type] << " "
                 << w->id << " has " << weapon_report(w) << "\n";
        }
    }

    void run() {
        static const int event_minute[10] = {0, 5, 10, 20, 30, 35, 38, 40, 50, 55};

        for (int hour = 0; ; ++hour) {
            for (int idx = 0; idx < 10; ++idx) {
                int m = event_minute[idx];
                int now = hour * 60 + m;
                if (now > T) return;

                if (m == 0) {
                    give_birth(now);
                } else if (m == 5) {
                    lion_runaway(now);
                } else if (m == 10) {
                    march(now);
                    if (war_end) return;
                } else if (m == 20) {
                    city_produce_elements();
                } else if (m == 30) {
                    city_take_elements_30(now);
                } else if (m == 35) {
                    arrow_shot_35(now);
                } else if (m == 38) {
                    bomb_38(now);
                } else if (m == 40) {
                    battle_40(now);
                } else if (m == 50) {
                    report_hq_50(now);
                } else if (m == 55) {
                    report_weapon_55(now);
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;
    for (int cs = 1; cs <= t; ++cs) {
        int M, N, R, K, T;
        cin >> M >> N >> R >> K >> T;

        int life[5];
        int atk[5];
        for (int i = 0; i < 5; ++i) cin >> life[i];
        for (int i = 0; i < 5; ++i) cin >> atk[i];

        cout << "Case " << cs << ":" << "\n";
        Game game(M, N, R, K, T, life, atk);
        game.run();
    }
    return 0;
}