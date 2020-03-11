#include<iostream>
#include<cmath>

using namespace std;

namespace big
{
    using std::sqrt;
    using std::pow;
    using std::ostream;
    using std::istream;
    using std::isdigit;
    using std::string;
    using std::swap;

    typedef int Len_Type;
    typedef int Pow_Type;

    typedef signed long long int General1;
    typedef const string& General2;

    class big_num
    {
    //private:
    public:
        char* num;
        Len_Type len;
        bool neg;
        bool inf;
        big_num();
        big_num(const big_num&);
        big_num(General1);
        big_num(General2);
        ~big_num();
        bool iseven() const;
        bool isodd() const {return !(this->iseven());}
        Len_Type size() const {return len;}
        bool isneg() const {return neg;}
        bool isinf() const {return inf;}
        //int operator[](Len_Type n) const throw(std::out_of_range);
        bool set(Len_Type i, char n);
        big_num& operator+=(const big_num& n) {return (*this = *this + n);}
        big_num& operator-=(const big_num& n) {return (*this = *this - n);}
        big_num& operator*=(const big_num& n) {return (*this = *this * n);}
        big_num& operator/=(const big_num& n) {return (*this = *this / n);}
        big_num& operator%=(const big_num& n) {return (*this = *this % n);}
        big_num& operator=(const big_num& n);
        bool operator==(const big_num&) const;
        bool operator!=(const big_num& n) const {if (inf || n.inf) return false; return !(*this == n);}
        bool operator>(const big_num&) const;
        bool operator<(const big_num& n) const {if (inf || n.inf) return false; return !(*this >= n);}
        bool operator<=(const big_num& n) const {if (inf || n.inf) return false; return !(*this > n);}
        bool operator>=(const big_num&) const;
        big_num operator-() const;
        big_num operator+(const big_num&) const;
        big_num operator-(const big_num&) const;
        big_num operator*(const big_num&) const;
        big_num operator/(const big_num&) const;
        big_num operator%(const big_num&) const;
        friend big_num sqrt(const big_num&);
        friend big_num pow(const big_num&, Pow_Type);
        friend ostream& operator<<(ostream&, const big_num&);
        friend istream& operator>>(istream&, big_num&);
        friend int intValue(const big_num&);
    };

    template <typename T>
    Len_Type digits(T);

    inline int abs (General1 n) {return (n < 0) ? -n : n;}

    template <typename T>
    Len_Type digits(T n)
    {
        if (n == 0)
            return 1;

        Len_Type sum = 0;
        while (n != 0)
        {
            n /= 10;
            sum++;
        }

        return sum;
    }

    big_num::big_num()
    {
        num = NULL;
        len = 0;
        neg = false;
        inf = true;
    }

    big_num::big_num(const big_num& in)
    {
        len = in.len;
        num = new char[in.len];
        for (register int i = 0; i < in.len; i++)
            num[i] = in.num[i];
        neg = in.neg;
        inf = in.inf;
    }

    big_num::big_num(General1 in)
    {
        if (in < 0)
            neg = true;
        else
            neg = false;

        in = abs(in);

        len = digits(in);
        num = new char[len];
        inf = false;
        for (register int i = 0; i<len; i++)
        {
            num[i] = in % 10;
            in /= 10;
        }
    }

    big_num::big_num(General2 in)
    {
        len = in.size();
        inf = false;
        if (in[0] == '-')
        {
            neg = true;
            len--;
        }
        else
            neg = false;
        num = new char[len];
        for (register int i = 0; i < len; i++)
        {
            if (isdigit(in[in.size()-1-i]))
            {
                num[i] = in[in.size()-1-i]-'0';
            }
            else if (!(in.size()-1-i == 0 && in[in.size()-1-i] == '-'))
            {
                    inf = true;
                    delete [] num;
                    num = NULL;
                    len = 0;
                    break;
            }
        }
    }

    big_num::~big_num()
    {
        delete [] num;
    }

    bool big_num::iseven() const
    {
        if (num[0] == 0 || num[0] == 2 || num[0] == 4 || num[0] == 6 || num[0] == 8)
            return true;
        return false;
    }

    /*int big_num::operator[](Len_Type n) const throw(std::out_of_range)
    {
        if (n > len-1 || n < 0)
            throw std::out_of_range ("Big_Num Class: Operator [] Used With Out Of Range Value");
        else
            return num[len-1-n];
    }*/

    bool big_num::set(Len_Type i, char n)
    {
        if (i > len || n > 9 || n < 0 || i < 1)
            return false;
        else
        {
            num[len-i] = n;
            return true;
        }
    }

    big_num& big_num::operator=(const big_num& in)
    {
        delete [] num;
        len = in.len;
        num = new char[in.len];
        for (register int i = 0; i < in.len; i++)
            num[i] = in.num[i];
        neg = in.neg;
        inf = in.inf;
    }

    bool big_num::operator==(const big_num& in) const
    {
        if (inf || in.inf)
            return false;
        if (neg != in.neg)
            return false;
        if (len != in.len)
            return false;
        for (register int i = 0; i < len; i++)
            if (num[i] != in.num[i])
                return false;
        return true;
    }

    bool big_num::operator>=(const big_num& in) const
    {
        if (inf || in.inf)
            return false;
        if (*this > in || *this == in)
            return true;
        return false;
    }

    bool big_num::operator>(const big_num& in) const
    {
        if (inf || in.inf)
            return false;
        if (len > in.len)
            if (neg)
                return false;
            else
                return true;
        if (len < in.len)
            if (neg)
                return true;
            else
                return false;
        for (register int i = len-1; i >= 0; i--)
        {
            if (num[i] > in.num[i])
                if (neg)
                    return false;
                else
                    return true;
            if (num[i] < in.num[i])
                if (neg)
                    return true;
                else
                    return false;
        }
        return false;
    }

    big_num big_num::operator-() const
    {
        if (inf)
            return *this;
        big_num temp = *this;
        if (temp.num != 0)
        {
            if (temp.neg)
                temp.neg = false;
            else
                temp.neg = true;
        }
        return temp;
    }

    big_num big_num::operator+(const big_num& in) const
    {
        if (inf || in.inf)
            return *this;
        const big_num& large = (len < in.len) ? in : *this;
        const big_num& small = (len < in.len) ? *this : in;

        big_num temp = large;

        //Control Negative And Positive Start
        if (neg && in.neg)
            temp.neg = true;
        else if (!neg && !in.neg)
            temp.neg = false;
        else if (neg && !in.neg)
        {
            big_num tmp = *this;
            tmp.neg = false;
            if (tmp <= in)
            {
                temp = in-tmp;
                temp.neg = false;
            }
            else
            {
                temp = tmp-in;
                temp.neg = true;

            }
            return temp;
        }
        else if (!neg && in.neg)
        {
            big_num tmp = *this;
            tmp.neg = true;
            if (tmp <= in)
            {
                temp = in-tmp;
                temp.neg = false;
            }
            else
            {
                temp = tmp-in;
                temp.neg = true;
            }
            return temp;
        }
        //Control Negative And Positive End

        int carry = 0;
        for (register int i = 0; i < small.len; i++)
        {
            carry += num[i]+in.num[i];
            temp.num[i] = carry % 10;
            carry /= 10;
        }

        if (carry)
        {
            for (register int i = small.len; i < large.len; i++)
            {
                carry += large.num[i];
                temp.num[i] = carry % 10;
                carry /= 10;
            }
        }

        if (carry)
        {
            int lent = digits(carry);
            char* tmp = new char[large.len+lent];
            for (register int i = 0; i < large.len; i++)
                tmp[i] = temp.num[i];
            for (register int i = large.len; i < large.len+lent; i++)
            {
                tmp[i] = carry % 10;
                carry /= 10;
            }
            delete [] temp.num;
            temp.len = large.len+lent;
            temp.num = tmp;
        }

        return temp;
    }

    big_num big_num::operator-(const big_num& in) const
    {
        if (inf || in.inf)
            return *this;
        const big_num& small = (!neg) ? ((*this < in) ? *this : in) : ((*this < in) ? in : *this);
        const big_num& large = (!neg) ? ((*this < in) ? in : *this) : ((*this < in) ? *this : in);

        big_num temp = large;

        //Control Negative And Positive Start
        if (neg && in.neg)
        {
            if (*this <= in)
                temp.neg = false;
            else
                temp.neg = true;
        }
        else if (!neg && !in.neg)
        {
            if (*this < in)
                temp.neg = true;
            else
                temp.neg = false;
        }
        else if (neg && !in.neg)
        {
            big_num tmp = *this;
            tmp.neg = false;
            temp = tmp + in;
            temp.neg = true;
            return temp;
        }
        else if (!neg && in.neg)
        {
            big_num tmp = *this;
            tmp.neg = true;
            temp = tmp+in;
            temp.neg = false;
            return temp;
        }
        //Control Negative And Positive End

        for (register int i = 0; i < small.len; i++)
        {
            if (small.num[i] > temp.num[i])
            {
                temp.num[i] = temp.num[i]-small.num[i] + 10;
                temp.num[i+1]--;
            }
            else
                temp.num[i] = temp.num[i]-small.num[i];
        }


        for (register int i = small.len; i < large.len-1; i++)
            if (temp.num[i] < 0)
            {
                temp.num[i] += 10;
                temp.num[i+1]--;
            }
            else
                break;

        int bac = temp.len;

        for (register int i = temp.len - 1; i > 0; i--)
            if (temp.num[i] == 0)
                temp.len--;
            else
                break;

        if (temp.len != bac)
        {
            char* tmp = new char[temp.len];
            for (register int i = 0; i < temp.len; i++)
                tmp[i] = temp.num[i];
            delete [] temp.num;
            temp.num = tmp;
        }

        return temp;
    }

    big_num big_num::operator*(const big_num& in) const
    {
        if (inf || in.inf)
            return *this;

        if (*this == 0)
            return *this;

        if (in == 0)
            return 0;

        big_num temp = 0;

        for (register int i = 0; i < in.len; i++)
        {
            string res = "";
            int carry = 0;

            for (register int j = 0; j < len; j++)
            {
                carry += in.num[i]*num[j];
                res += (carry % 10) + '0';
                carry /= 10;
            }
            while (carry)
            {
                res += (carry % 10) + '0';
                carry /= 10;
            }
            for (register int j = 0; j < res.size()/2; j++)
                swap(res[j],res[res.size()-1-j]);
            for (register int j = 0; j < i; j++)
                res += '0';
            temp += res;
        }

        temp.neg = neg ^ in.neg;

        return temp;
    }

    big_num big_num::operator/(const big_num& in) const
    {
        if (inf || in.inf)
            return *this;

        if (*this == 0)
            return 0;

        if (in == 0)
        {
            big_num temp;
            temp.inf = true;
            return temp;
        }

        if (*this < in)
            return 0;

        string res = "";
        string str = "";
        register int i;
        for (i = 0; i < in.len; i++)
            str += num[len-1-i]+'0';
        if (in > str)
        {
            str += num[len-1-i]+'0';
            i++;
        }
        big_num tmp = str;
        int div = 0;
        while ((in*div) <= tmp)
            div++;
        div--;
        res += div+'0';
        for (register int j = i; j < len; j++)
        {
            tmp -= in*div;
            tmp *= 10;
            tmp += num[len-1-j];
            div = 0;
            while ((in*div) <= tmp)
                div++;
            div--;

            res += div+'0';
        }

        return res;
    }

    big_num big_num::operator%(const big_num& in) const
    {
        if (inf || in.inf)
            return *this;
        return (*this)-(*this/in)*in;
    }

    big_num sqrt(const big_num& in)
    {
        if (in.inf)
            return in;
        string res = "";
        if (in.neg)
        {
            big_num temp;
            temp.inf = true;
            return temp;
        }
        if (in.len == 0)
            return 0;
        int first,f_rem;
        if (in.len % 2 == 1)
        {
            first = in.num[in.len-1];
            f_rem = 1;
        }
        else
        {
            first = in.num[in.len-1]*10+in.num[in.len-2];
            f_rem = 2;
        }
        res += sqrt(first);
        big_num remain = first-pow(int(res[0]),2);
        res[0] += '0';
        big_num temp = res;
        for (register int i = in.len-1-f_rem; i >= 0; i -= 2)
        {
            big_num tmp = remain*100+in.num[i]*10+in.num[i-1];
            temp *= 2;
            string str = "";
            for (register int j = temp.len-1; j >= 0; j--)
                str += temp.num[j]+'0';
            int k;
            for (register int j = 0; j < 10; j++)
            {
                big_num tempp = str + char(j+'0');
                if (tempp*j > tmp)
                {
                    k = j-1;
                    break;
                }
                else if (j == 9)
                    k = 9;
            }
            str += k + '0';
            remain = tmp-big_num(str)*k;
            res += k + '0';
            temp = res;
        }

        return temp;
    }

    big_num pow(const big_num& in, Pow_Type n)
    {
        if (in.inf)
            return in;
        if (n == 0 && in == 0)
        {
            big_num temp;
            temp.inf = true;
            return temp;
        }
        if (in == 0)
            return 0;
        big_num temp = 1;
        for (register int i = 0; i < n; i++)
            temp *= in;

        return temp;
    }

    ostream& operator<<(ostream& os, const big_num& in)
    {
        if (in.inf)
        {
            os << "INF";
            return os;
        }
        if (in.neg)
            os << '-';
        for (register int i = in.len-1; i >= 0; i--)
            os << int(in.num[i]);
        return os;
    }
    istream& operator>>(istream& is, big_num& in)
    {
        string str;
        is >> str;
        in = str;
        return is;
    }
};

using namespace big;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    big_num a, b, i, j, ans("0");
	cin >> a >> b;
    i = a;
    while (i <= b)
    {
        j = i + 1;
        while (j <= b)
        {
            for (int x = 0; x <= i.len - 1; x++)
                ans += abs(i.num[x] - j.num[x]);
            for (int x = i.len; x <= j.len - 1; x++)
                ans += j.num[x];
            j = j + 1;
        }
        i = i + 1;
    }
    ans = ans % 1000000007;
    ans = (ans + ans) % 1000000007;
    cout << ans << endl;
}
