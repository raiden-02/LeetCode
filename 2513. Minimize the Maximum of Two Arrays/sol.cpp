class Solution {
    // A – A = Ø
    // B – A = B⋂A’
    // B – A = B – (A⋂B)
    // n(AUB) = n(A – B) + n(B – A) + n(A⋂B)
    // n(A – B) =  n(A∪B) – n(B)
    // n(A – B) = n(A) – n(A⋂B)
    // (A – B) = A if A⋂B =  Ø
    // (A – B) ⋂ C = (A⋂ C) – (B⋂C)
    // n(A‘) = n(∪) – n(A)
public:
    int minimizeSet(long long divisor1, long long divisor2, long long ucnt1, long long ucnt2) {
        long long l = 1, r = 1e10;

        while(l < r - 1) {
            long long mid = l + (r - l) / 2;

            long long A = mid / divisor1;
            long long B = mid / divisor2;
            long long Ac = mid - A; // elements not div by divisor1
            long long Bc = mid - B; //elements not div by divisor2
            long long AiB = mid / lcm(divisor1, divisor2); 
            long long AuB = A + B - AiB;
            long long AciBc = mid - AuB; //elements not divisible by both

            long long elements4Arr1 = Ac - AciBc >= ucnt1 ? 0 : ucnt1 - (Ac - AciBc);
            long long elements4Arr2 = Bc - AciBc >= ucnt2 ? 0 : ucnt2 - (Bc - AciBc);

            if(elements4Arr1 + elements4Arr2 <= AciBc)
                r = mid;
            else
                l = mid;
        }

        return r;
    }
};
