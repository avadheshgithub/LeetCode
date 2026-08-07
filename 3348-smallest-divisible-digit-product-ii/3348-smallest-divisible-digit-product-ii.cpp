class Solution {
    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factors get_digit_factors(int d) {
        Factors f;
        while (d > 0 && d % 2 == 0) { f.c2++; d /= 2; }
        while (d > 0 && d % 3 == 0) { f.c3++; d /= 3; }
        while (d > 0 && d % 5 == 0) { f.c5++; d /= 5; }
        while (d > 0 && d % 7 == 0) { f.c7++; d /= 7; }
        return f;
    }

    int get_min_digits(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        int count = c5 + c7;
        count += c3 / 2;
        int rem_c3 = c3 % 2;

        count += c2 / 3;
        int rem_c2 = c2 % 3;

        if (rem_c3 == 1 && rem_c2 == 1) {
            count += 1; // digit 6
        } else if (rem_c3 == 1 && rem_c2 == 2) {
            count += 2; // digits 2, 6
        } else if (rem_c3 == 1 && rem_c2 == 0) {
            count += 1; // digit 3
        } else if (rem_c3 == 0) {
            if (rem_c2 == 2) count += 1; // digit 4
            else if (rem_c2 == 1) count += 1; // digit 2
        }
        return count;
    }

    string construct_suffix(int rem_len, int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        string digits = "";
        for (int i = 0; i < c7; i++) digits += '7';
        for (int i = 0; i < c5; i++) digits += '5';

        for (int i = 0; i < c3 / 2; i++) digits += '9';
        int rem_c3 = c3 % 2;

        for (int i = 0; i < c2 / 3; i++) digits += '8';
        int rem_c2 = c2 % 3;

        if (rem_c3 == 1 && rem_c2 == 1) {
            digits += '6';
        } else if (rem_c3 == 1 && rem_c2 == 2) {
            digits += "26";
        } else if (rem_c3 == 1 && rem_c2 == 0) {
            digits += '3';
        } else if (rem_c3 == 0) {
            if (rem_c2 == 2) digits += '4';
            else if (rem_c2 == 1) digits += '2';
        }

        while ((int)digits.length() < rem_len) {
            digits += '1';
        }

        sort(digits.begin(), digits.end());
        return digits;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors t_fac;
        long long temp_t = t;
        while (temp_t % 2 == 0) { t_fac.c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { t_fac.c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { t_fac.c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { t_fac.c7++; temp_t /= 7; }

        if (temp_t > 1) return "-1";

        int n = num.length();
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // Compute prefix factor sums
        vector<Factors> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if (num[i] != '0') {
                Factors f = get_digit_factors(num[i] - '0');
                pref[i + 1].c2 += f.c2;
                pref[i + 1].c3 += f.c3;
                pref[i + 1].c5 += f.c5;
                pref[i + 1].c7 += f.c7;
            }
        }

        // Check if num itself is valid
        if (first_zero == n) {
            if (pref[n].c2 >= t_fac.c2 && pref[n].c3 >= t_fac.c3 &&
                pref[n].c5 >= t_fac.c5 && pref[n].c7 >= t_fac.c7) {
                return num;
            }
        }

        // Try replacing digit at index i
        for (int i = n - 1; i >= 0; i--) {
            if (i > first_zero) continue;

            int start_d = (num[i] == '0') ? 1 : (num[i] - '0' + 1);
            for (int d = start_d; d <= 9; d++) {
                Factors f = get_digit_factors(d);
                int req2 = t_fac.c2 - pref[i].c2 - f.c2;
                int req3 = t_fac.c3 - pref[i].c3 - f.c3;
                int req5 = t_fac.c5 - pref[i].c5 - f.c5;
                int req7 = t_fac.c7 - pref[i].c7 - f.c7;

                int rem_len = n - 1 - i;
                if (get_min_digits(req2, req3, req5, req7) <= rem_len) {
                    string ans = num.substr(0, i) + to_string(d) +
                                 construct_suffix(rem_len, req2, req3, req5, req7);
                    return ans;
                }
            }
        }

        // If length N is impossible, increase string length
        int min_len_t = get_min_digits(t_fac.c2, t_fac.c3, t_fac.c5, t_fac.c7);
        int target_len = max(n + 1, min_len_t);
        return construct_suffix(target_len, t_fac.c2, t_fac.c3, t_fac.c5, t_fac.c7);
    }
};