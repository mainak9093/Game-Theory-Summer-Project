#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n, 0);
        for (auto &x : v) cin >> x;

        // till any x moves , ceil(x/2) are of Aria and floor(x/2) are of Dannus
        //This is her leverage over Darrus the SITH Lord. This is her force power :fire:
        vector<ll> sorted, reverse_sorted;
        for (int i = 0; i < n; i++)
        {
            sorted.push_back(i + 1);
            reverse_sorted.push_back(n - i);
        }

        // Let's distribute them into 3 sets
        // Aria's need a fix exclusively: wa
        // Darrus needs a fix exclusively: wd
        // Common fixes both need fix no "exclusively thingy" = wc
        ll wa = 0, wd = 0, wc = 0;
        for (int i = 0; i < n; i++)
        {
            bool bad_index_for_a = (v[i] != sorted[i]);
            bool bad_index_for_d = (v[i] != reverse_sorted[i]);
            if (bad_index_for_a && !bad_index_for_d) wa++;
            else if (!bad_index_for_a && bad_index_for_d) wd++;
            else if (bad_index_for_a && bad_index_for_d) wc++;
        }
        // cout << wa << " " << wd << " " << wc << endl;

        // CASE 1: wa == wd && wc == 0 → Aria wins (she moves first, and wins on rearrange)
        if (wa == wd && wc == 0)
        {
            cout << "First" << endl;
        }
        // CASE 2: wa < wd && wc <= (wd - wa) → Aria unlocks all her exclusives and still has less commons to deal with
        else if (wa < wd && wc <= (wd - wa))
        {
            cout << "First" << endl;
        }
        // CASE 3: wa < wd && (wd - wa) < wc → Tie (Darrus has enough exclusives, but commons allow stalling)
        else if (wa < wd && (wd - wa) < wc)
        {
            cout << "Tie" << endl;
        }
        // CASE 4: wa > wd && (wa - wd) > wc → Darrus wins (Aria has more to fix than commons can buffer)
        else if (wa > wd && (wa - wd) > wc)
        {
            cout << "Second" << endl;
        }
        // CASE 5: wa > wd && (wa - wd) <= wc → Tie
        else if (wa > wd && (wa - wd) <= wc)
        {
            cout << "Tie" << endl;
        }
        else
        {
            cout << "Tie" << endl;
        }

        /*
        ███████████████████████████████████████████████████████████████████████████████
        █                             The Strategies :)                             █
        ███████████████████████████████████████████████████████████████████████████████

        -> Dominant Strategy:
            → Always free your own exclusive mismatches first.
            → Only touch the common positions when your exclusives are done
              *and* opponent has fewer exclusives left.(cases are based on these)

        -> Aria's Optimal Strategy:
            → Being the first player, Aria uses her early moves to clear her wa (Aria-only).
            → Then stalls until Darrus commits to clearing his set. Being the first player for any point fo time she has >= moves then darrus either equal or +1
            → If enough wc remain and Darrus can’t eat them all, she forces a win or tie.
            → Avoid freeing common spots early — it gives Darrus stall leverage.

        -> Danrus' Optimal Strategy:
            → Clear wd (Darrus-only) as early as possible.
            → Stall it if Aria clears hers faster.
            → If Aria has more to do and wc < wa - wd, he can outlast her into a win. If he finished early he cant loose, he can either force a win or stall and draw
        NOTE: The Winning strategy is more of a not to loose strategy, we always focus on what moves
        can affect our winnings. If we can loose due to taking a move now, we stall, either we stall indefinetley, or teh opponent moves, which would be in our benefit since this is why we were stalling? :)

        ░ Winning Strategy by Case:

            ● Case 1: wa == wd && wc == 0
                → Aria wins by consuming all exclusives; Darrus can't respond.(Arya takes first thats why and stalling will hv no effect)

            ● Case 2: wa < wd && wc <= (wd - wa)
                → Aria wins by staliing after using up her wa; Darrus runs out of safe moves.

            ● Case 3: wa < wd && wc > (wd - wa)
                → Tie — both players can enter a stall cycle on common slots.

            ● Case 4: wa > wd && (wa - wd) > wc
                → Darrus wins — he clears his faster, and Aria can't stall long enough.

            ● Case 5: wa > wd && (wa - wd) <= wc
                → Tie — Aria's extras balanced by enough common spots to neutralize darrus win, and stall exists too.
            In a more explanative tone read the following
// CASE 1: wa==wd  wc==0
// in this case Aria wins because even if Dannus stalls he becomes far from victory
//Alternatively the last free would be used by Dannus therefore, Aria gets a shot at rearrange
//CASE 2: wa<wd && wc<=wd-wa
//Aria eats up all her exclusives, leaving Dannus with wd-wa exclusives and wc commons
// now if wc<=wd-wa then obviously she will unlock the commons and yet win(heere equality is because Aria goes first)
//CASE 3: wa<wd && wd-wa<=wc here dannus will fill all his exclusives first and then they wouldnt end up
//deciding who eats the last common piece so A TIE
//CASE 4: wa>wd && wa-wd>wc
// Dannus eats all his and Aria is left with wa-wd things now even if she stalls if wa-wd>wc then Dannus will take those wc first dominant startegy
//CASE 5: wa>wd && wa-wd<=wc
// SAME CASE TIE and rest any possibility if remain it is a TIE

        */
    }
}
