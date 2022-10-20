                              Arrays 
                              
1. Product  of array Except itself 

vector<long long int> productExceptSelf(vector<long long int>& arr, int n) 
    {
          vector<long long> ans(n,0);
          long long pro=1;
          int count=0,ind=0;
           for(int i=0; i<n; i++)
            {
               if(arr[i]!=0 && count<2)
                pro = pro*arr[i];
               else 
               { count++;  ind=i; }
            }
          
            if(count<1)
              {
                  for(int i=0; i<n; i++)
                    ans[i]=pro/arr[i];
              }
              
            else if(count ==1)
                 ans[ind]=pro;
           
            return ans;
    }

2. Find Pivot Index-->sum strictly equal to left and right
        //  Prefix Sum Problem TC- O(n)   SC -O(1)
   int pivotIndex(vector<int>& nums) 
    {
        int left=0, Tsum=0,n=nums.size();
       
        for(int i=0; i<n; i++)
             Tsum += nums[i];
        
        for(int i=0; i<n; i++)
            if(left== Tsum-left-nums[i])
                return i;
            else left +=nums[i];
        return -1;
    }
   
3. Move Zeroes  At End   
  void moveZeroes(vector<int>& nums)  
    {
        int i=0,j=0,n=nums.size();
        
        while(i<n && j<n)
        {
            if(nums[i]==0)
            {   
                j++;
               if(j<n && nums[j]!=0)
               {
                   swap(nums[i],nums[j]);
                   i++;
               }
            }
             else   {i++;j++;}
        }
    }
void moveZeroes(vector<int>& nums) {
 for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
     {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}

4. Rearrange an array with O(1) extra space ;
        // arr[arr[i]]  becomes == arr[i] ;
   void arrange(long long arr[], int n) 
    {
        for(int i=0;i<n ;i++)
            arr[i] +=(arr[arr[i]%n])%n*n;
        
        for(int i=0; i<n; i++)
              arr[i] /=n;
    }

4.(a)     //Recursive approach space O(1)
      void fun(long long arr[],int n,int k)
   {
       if(k>=n) return;
       int i=arr[arr[k]];
       fun(arr,n,k+1);
       arr[k]=i;
   }
   void arrange(long long arr[], int n) {
       fun(arr,n,0);
   }


5. Majority Element in Array //{ count> n/2 }
    // Moore's Majority Voting Algorithm 
  int majorityElement(int a[], int size)
    {
         int count =1,major = a[0];
         for(int i= 1; i<size ; i++)
          {
              if(count==0)
              {
                  major = a[i];
                   count=1;
              }
              else if(major==a[i]) //if current ele match 
                    count++;
            
              else count--;
          }
          
          count =0;
          for(int i=0; i<size; i++)
             if(a[i]==major) count++ ;
          
          if(count>size/2) return major;
          else return -1;
    }

6. Cumulative frequency of elements in an unsorted array
 
   vector<int> countFreq(int arr[], int n) 
    { 
        vector<int> ans;
        map <int,int> ump;   // declaring map 
        for(int i=0; i<n ;i++)
          {
              ump[arr[i]]++; //counting frequency key to value
          }
          int count=0;
         for(auto it:ump)
           {
              count+=it.second;  // getting mapped element with key
               ans.push_back(count);
           }
           return ans;
    } 

7. Find duplicates in an array // Array returned //Modified
        //   0<=arr[i]<=N-1
   vector<int> duplicates(int arr[], int n)
    {
       vector<int> ans; 
       for(int i=0; i<n; i++)
       {
            arr[arr[i]%n] +=n;
       }
       for(int i=0; i<n;i++)
         {
            if((arr[i]/n)>1)
               ans.push_back(i);
         }
        if(ans.size()==0)
           ans.push_back(-1);
        return ans;
    }

8. Subarray with 0 sum // if Any Exists
     bool subArrayExists(int arr[], int n)
    {
        int ans=0; 
        for(int i=1; i<n; i++)
          {
              arr[i] += arr[i-1] ; // prefix sum  of  Array 
          }
             // if array repeats value then sum=0  occured
         map<int,int> dup;
         for(int i=0; i<n; i++)
         {
            dup[arr[i]]++; // maping element with frequency
            if(dup[arr[i]]==2  or arr[i]==0)
              {
                  ans=1;  break;
              }
         }
         return ans;
    }

9. Common elements in 3 Sorted Array 
      // Take Care of Dublicates in  Returned array 
       // Without any additional data stucture
   vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {          
            int i=0,j=0,k=0;
            vector<int> v; 
             while(i<n1 && j<n2 && k<n3)
             {
                 if(A[i]==B[j] && A[i]==C[k]) 
                 {
                     if(!v.empty() and v[v.size()-1]!=A[i])
                           v.push_back(A[i]);
                      else if(v.empty())
                        v.push_back(A[i]);
                     i++;j++;k++;
                 }
                 if(A[i]<B[j] || A[i]<C[k]) i++;
                 if(B[j]<A[i] || B[j]<C[k]) j++;
                 if(C[k]<A[i] || C[k]<B[j]) k++;
             }
             return v;
        }

10. Circular Prime Number // 197, 719, 971
    // if all circular rotation is prime
        int isCircularPrime(int n) 
    {
        int k =n,count =-1,digit;
          while(k>0)
          {
              k/=10;
              count++;
          }
          k=count;
        if(isPrime(n))
           {
             while(k--) // rotations = count
             {
                digit = n%10;
                n=n/10;
                n= digit * pow(10,count)+n;
               if(isPrime(n))  continue;
               else return 0;
             }
           }
         else return 0;
          return 1;
    }

11.  bool isPrime (int n)
    {
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
   }

12. Find Rank Transform in  an Array
     //  Find Inedex of an Set in O(1)TC & O(N)SC
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        set <int> myset(arr.begin(),arr.end());
        unordered_map<int ,int > hash;
         int rank =1;
        for(auto &i: myset) hash[i] = rank++;
        for(auto &i: arr) i = hash[i]; 
        return arr ;
    }

13. Find Missing And Repeating //  {1, 2, …N} size--> N
       // Sign Changing Method to find Duplicate

    int *findTwoElement(int *arr, int n)
    {
        int ans[2];
       for(int i=0; i<n; i++)
         {
              int temp=abs(arr[i]);
              if(arr[temp-1]<0)
                  {
                    ans[0]= temp;
                     continue;
                  }
             if(arr[temp-1]>0)
                arr[temp-1] *=-1;
         }
      
       for(int i=0; i<n; i++)
         {
             int temp=abs(arr[i]);
             if(arr[i]>0)
               {
                  ans[1]= i+1;
                   break;
               }
         }
         return ans; 
    }

14. Array Subset of another array //O(n) ,O(n)
   string isSubset(int a1[], int a2[], int n, int m) 
{
    unordered_set<int> s(a1, a1+n);
    for(int i=0; i<m;i++)
    {
        if(s.count(a2[i]))
             continue;
        
           return "No";
    }
    return "Yes";
}

15. Count of Set Bits  // complexity O(no. of set bits ~ logN)
    int setBits(int N)
        {
            if(N==0)
                return 0;
            else
              return 1+setBits(N & N-1);
        }

16. Decimal to binary // Using Bitwise Operaters
       //  complexity O(logN)
  void toBinary(int N)
{
    int bin_Str[32],i;
    for(i=0; N>0; i++)
    {
        bin_Str[i] = N&1;
        N >>= 1 ;   //equivalent to divide by 2
    }
    for(int j=i-1; j>=0; j--)
     {
         printf("%d",bin_Str[j]); //reverse Printing
     }
}
15. Finding a Duplicate Number // All present except one
     int findDuplicate(vector<int>& nums) 
    {
        int ans=0 ;  // N+1 elements
       for(int i=0; i<nums.size(); i++)
            ans= ans^nums[i];
        // Taking XOR with 1 to N 
       for(int i=1; i<nums.size(); i++)
          ans = ans^i;
        return ans;
    } 

16. Power of 2  // N& N-1 counted set bits 
     bool isPowerofTwo(long long n)
    {
       if(n==0) return 0;
        return  !(n&n-1);
    }

17. Sum  equal to XOR in Given range 
     // (N & 1 ==0)counted unset bits
   long sumXor(long n) 
{
    int ct=0;
    while (n>0) 
    {
        if((n&1)==0) ct++;
        n>>=1;
    }   
    return pow(2,ct); 
}

18. Number of Flips to make binary A to B;
     int numberOfFlips(int a, int b) 
    {
        int count=0;
        while( a>0 || b>0)
        {
            if(((a&1)^(b&1))==1)  count++;
            a>>=1;  b>>=1;
        }
        return count;
    }

19. Sort by Set Bit Count
    class Solution{
    public:
      static int count(int n)
      {
          int res=0;
          while(n>0)
          {
              res++;
              n=n&(n-1);
          }
          return res;
      }
      static bool cmp(int a ,int b)
        {
            if(count(a)>count(b))  return true;
            else return false;
        }
    void sortBySetBitCount(int arr[], int n)
    {
       stable_sort(arr,arr+n,cmp);
    }
};

    IMP->    if (X^Y) or (Y^Z) or (X^Z) == 1 
    // then at least one bit must be different

20. XOR Game gfg - Find n such that N&N+1==k ; 
    int xorCal(int k)
    {
        if(k==1) return 2;
       
       int x = k & (k + 1);
      
      if(x != 0) return -1;
      else  return (k+1)/2 -1;
    }

21. Longest consecutive subsequence- numbers can be in any order.
  //  Input: N = 7 a[] = {2,6,1,9,4,5,3} % Output:6
   int longestConsecutive(vector<int>& nums) 
    {
         unordered_set<int> hash ; 
         for(auto  i : nums)
            hash.insert(i);
         
        int max = 0 ;
         for(auto i : hash)
         {
             int ct=0;
              if(!hash.count(i-1))
              {
                  while(hash.count(i++))
                  {
                      ct++;
                     if(max<ct) max = ct;
                  }  
              }
         }
        return max;
    }

22. Count triplets with sum smaller than X - 3Sum
             // Two Pointers Aapproach
  long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr,arr+n);
        long long sol =0; 
        for(int i =0; i<n-2; i++)
        {  
            int j=i+1,k=n-1; 
               while(j<k)
               {
                  if(arr[i]+arr[j]+arr[k]<sum) 
                    {
                        sol +=(k-j);
                        j++;
                    }
                   else   k--;
               }
           }
             return sol;
        }

23. Maximum Subarray Sum  // include negative numbers
  long long maxSubarraySum(int arr[], int n)
{   // kadane's algo
     long long maxm=0,max=arr[0];
    for(int i=0; i<n ;i++)
    {
        if((arr[i]+maxm)>0)
        {
            maxm=maxm+arr[i];
            if(max<maxm) max=maxm;
        }  
        else  maxm=0; //maxm = arr[0]
        // for minimunm  1 element from arr
        if(max<arr[i])
              max = arr[i];
    }
    return max;
}

24. Rearrange Array Alternately - MAX MIN ALTERNATE
  void rearrange(long long *arr, int n) 
    { 
        long long N = arr[n-1]+1;
        long long i=0,j=n-1,k=0;
         while(i<n)
         {
            arr[i] += (arr[j]%N)*N; // Storing max at even Index  j
              i++;  //  incremented traverse pointer
            if(i<n) 
            {
              arr[i] += (arr[k]%N)*N; // Storing min at odd index 
            }
            i++; j--;k++; // incrementing all  indices 
         }
         for(int i=0; i<n ;i++)
           {
              arr[i] = (arr[i]/N); //we hashed  Divident which is  new ans 
           }
    }

25. Count pairs with given SUM

 int getPairsCount(int arr[], int n, int k) 
    {
       unordered_map<int, int>m;
       int count = 0;
       for(int i = 0; i<n; i++)
        {  //  counting at the time before storing that element
            //  in this method we count only once (mutually)
           count = count + m[k-arr[i]];
           m[arr[i]]++;  //storing in map
       }
       return count;
     }
    // optimised way only one loop required  less calculations 
   int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int,int > hash;
        int ans=0;
         for(int i=0; i<n ;i++)
          {
              int temp = k-arr[i];
              if(hash.count(temp))
                  ans += hash[temp]; // taking in account all  present pairs
               hash[arr[i]]++; //  storing in map even if it is present 
          }
          return ans ;
    }

26. Middle Element in A,B,C in minimum Comparisons
   int middle(int A, int B, int C)
    {
        int maxm = max(A,max(B,C));
        int minm = min(A,min(B,C));
        return (A+B+C-minm-maxm);
    }

27.  Maximum Absolute Sum of Any Subarray
    // DP - Use of Kadanes Algo
   // Crux of the prob. is magnitude is maxm when either it is 
// maxm subarray sum or minimum subarray sum 
 int maxAbsoluteSum(vector<int>& arr) 
    {
      int n = arr.size(),max=0,maxm=0,min=0,minm=0;
     for(int i=0; i<n ;i++)
       {
           if(max+arr[i]>0)
           {
               max += arr[i];
               if(maxm<max) maxm = max;
           }
           else max =0;
       }
     for(int i=0; i<n ; i++)
     {
         if(min+arr[i]<0)
         {
              min += arr[i];
             if(min<minm)
                 minm  =min;
         }
        else min = 0;
     }
        if(maxm>abs(minm))  return maxm;
        else return abs(minm);
    }

28. Segregate Even and Odd numbers using space
    void segregateEvenOdd(int arr[], int n) 
    {
        sort(arr,arr+n);
        int a[n],j=0,k=0;
        for(int i=0; i<n ; i++)
        {
            if(arr[i] &1);
            else a[j++]=arr[i];
        }
        // after k==j odd will automatically present in a[]
        for(int i=0; i<n; i++)
        {
            if(arr[i] &1)
                 a[j++]=arr[i];
             arr[i]=a[k++];  
        }
    }

28(b).Segregate Even and Odd numbers in O(1) --> constant space

   void segregateEvenOdd(int arr[], int n) 
    {
      int slow = -1;
      for(int fast=0; fast<n; j++)
       {
          if(arr[j]%2==0)
           {
            slow++;  // represents even indexes
            swap(arr[slow],arr[fast]);
           }
       }
       sort(arr,arr+slow+1);
       sort(arr+slow+1,arr+n);
    }

28(c)  or      Sort Array By Parity -- Leetcode
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),[](int a , int b){
              if((a%2==0) and (b%2==1)) return  true;
              return false ;
            });  
        return nums ;
    }
29.  Count Positive - Negative Pairs - Amazon Interview
   long long countPositiveNegativePairs(int arr[], int n)
{
    long long ans = 0; 
    unordered_map<int, int> m; 
    for(int i =0; i < n; i++) {
        m[arr[i]]++; 
    }
    for(auto it : m) {
        int f = it.first; 
        if(m.find(-1 * f) != m.end()) 
        {
            if(m[-1 * f] > 0) 
            {
                ans += (long long) m[f] * m[-1 * f]; 
                m[f] = 0; 
                m[-1 * f] = 0; 
            }
        }
    }
    return ans; 
}

30. Three 3Sum Closest  // If two close elemt ,return max one
  //   Input: target = 13 ,nums[] = {5,2,7,5}  Output: 14
   int threeSumClosest(vector<int> nums, int target)
    {
          sort(nums.begin(),nums.end());
        int n = nums.size(),ans=0,min=INT_MAX; //for first condition
         for(int i=0; i<n; i++)
         {
            int  j= i+1,k=n-1;
             while(j<k)
             {
                int sum =  nums[i]+nums[j]+nums[k];
                 if(sum==target)
                     return target;
                     
                 else if(sum>target)
                     {    //  saving the max target
                          if(sum-target<=min)
                             {
                                 ans = sum;
                                 min = sum-target;
                             }
                           k--;
                     }   
                 else
                 {
                     if(target-sum<min)
                           {
                               ans = sum;
                               min = target-sum;
                           }
                     j++;
                 }
             }
         }
        return ans;
    }
       


31. Three 3Sum - Find all Distinct Triplets sum equal to 0
      //     Input: nums = [-1,0,1,2,-1,-4]
        //    Output: [[-1,-1,2],[-1,0,1]]
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size(),j,k=n-1;
        vector<vector<int>> ans;
         for(int i=0; i<n; i++)
         {
             if(i==0 or (i>0 and nums[i]!=nums[i-1]))
             {
                 j= i+1; k=n-1;
                while(j<k)
                 {
                     if(nums[i]+nums[j]+nums[k]==0)
                    {
                      vector<int> v  = {nums[i],nums[j],nums[k]} ;
                        ans.push_back(v);
                         while(j<k && nums[j]==nums[j+1]) j++;
                         while(j<k && nums[k]==nums[k-1]) k--;
                         j++;k--;
                    }
                   else if(nums[i]+nums[j]+nums[k]>0)  k--;
                   else j++;
                 }   
             }
         }
        return ans;
    }
    
32. 4Sum Four Sum - Unique pairs sum equal to 0 (previoius)
vector<vector<int>> fourSum(vector<int>& arr, int target) 
    {
     int n = arr.size();
       sort(arr.begin(),arr.end()); // sorting to reduce complexity
       vector<vector<int>> ans ;
       for(int i=0; i<n-3; i++)
        {
            if(i>0 and arr[i]==arr[i-1]) continue; // must skip one pass
                
              for(int j=i+1; j<n-2; j++)
              {
                  if(j>i+1 and arr[j]==arr[j-1]) continue;  // after one pass
                  int k=j+1, l=n-1;
                  while(k<l)
                  {
                   long long nums = 1LL*arr[i]+arr[j]+arr[k]+arr[l];
                    // calculation will  held on long long  before store
                     if(nums==target)
                     {
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]} ;
                         ans.push_back(temp);
                         // Skipping Duplicates
                        while(k<l and arr[k]== arr[k+1]) k++; //check if next==prev
                        while(k<l and arr[l]== arr[l-1]) l--; // check if prev==next 
                         k++; l--; // increment 
                     }
                     else if(nums>target) l--; 
                     else  k++;
                  }
              }
        }
        return ans ;
    }

33. Longest/Largest subarray with 0 sum - O(N) -->TC & SC used Hashing
    //  idea is if sum 0 occur then prefix sum reapeats itself  
      int maxLen(vector<int>&A, int n)
    {   
        int len, mxlen=0,presum=0;
        unordered_map <int,int> hash;
    // mapping 0 as -1 if  0 occur instead of reapeation
          hash[presum] = -1;  // It Adds Length of +1 when 0 occurs when presum 0 occurs
     // it means all  element  till that point giving sum==0;
        for(int i=0; i<n; i++)
         {
             presum  += A[i]; // computing Prefix sum
             if(hash.count(presum))
             {
                 len = i - hash[presum] ; 
                 mxlen  = max(mxlen,len);
             }
             else hash[presum] = i; // mapping a index of presum
         }
          
         return mxlen ; 
    }

34. Next Permutation or Next Greater Permutation 

     void nextPermutation(vector<int>& nums) 
    {
         int n = nums.size(); //size of array
        // First of All We have to Find a Right Most Peak
         int peakInd = -1; // Assuming Initially No Peak Index
         int i=1; //  traverse Pointer
         while(i<n)
         {
              if(nums[i]>nums[i-1])
                  peakInd = i;
              i++;
         }
         // If No Peak found sequence is in Descensing Order
         // reversing  the Sequence
        if(peakInd==-1)
        {
            for(int i=0,j=n-1; i<j; i++,j--)
                swap(nums[i],nums[j]);
             return ;
        }
        // Special Case if peak is Available but there is an element
        // which is  greater than prepeak which also perform as a peak for that
        // for Next perMutation we must use minimum weight
         int  prev = peakInd-1,min=peakInd;
         for(int i=peakInd+1; i<n ;i++)
         {
             if(nums[prev]<nums[i] and nums[peakInd]>nums[i])
                  min = i; // selecting the right most index for min weight
         }
          swap(nums[min],nums[prev]); 
          sort(nums.begin()+peakInd,nums.end()); // sorting for ASC order
    }

35. Next Greater Element III - Next Greater Integer (if pOssible)
        //  Return -1 if it not fit in  32 bit Integer // 0ms Soln
    int nextGreaterElement(int n) 
    {  
       string nums = to_string(n);
       string max =  to_string (INT_MAX);
        int pkInd =-1,size = nums.size();
        for(int i=1; i<size ;i++)
        {
            if(nums[i]>nums[i-1])
                pkInd = i;
        }
         if(pkInd ==-1) return -1;
         
         int prev = pkInd-1,min=pkInd;
         for(int i=pkInd+1; i<size; i++)
         {
             if(nums[i]>nums[prev] and nums[i]<nums[pkInd])
                 min = i;
         }
         swap(nums[min],nums[prev]);
         sort(nums.begin()+pkInd,nums.end());
         if(nums.size()<10 or nums<=max) 
         {
             n = stoi(nums);
             return n;
         }
         else return  -1;
    }

36. Merge Sorted Array in Given Space - O(n) 
//     Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
             //          Output: [1,2,2,3,5,6]
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
       int i=m-1, j=n-1, k=m+n-1; 
        // pointers from back  Direction 
       while(i>=0 && j>=0)
       {
           if(nums1[i]>nums2[j])
           {
               // Copying greater element in Last
               nums1[k] = nums1[i];
                 k--; i--;
           }
           else
           {
              nums1[k] = nums2[j];
                 k--; j--;
           }
       }
        while(j>=0)
        {
          // copy remaining element of nums2 in nums1  
            nums1[k] = nums2[j];
                 k--; j--;
        }
       // No need to copy nums1 they are already in sorted Order
    }        

37. Rotate an Array  in Place - Left Rotation

   void rotateArr(int arr[], int d, int n)
    {
        // for left Rotation  rotate(d,n-d,n);
        // for right rotation R(n-d,d,n);
         d %= n ;
         int s=0,e=d-1;
         while(s<e)
            swap(arr[s++],arr[e--]);
      
         s=d; e=n-1;
         while(s<e)
            swap(arr[s++],arr[e--]);
         
         s=0; e= n-1;
         while(s<e)
            swap(arr[s++],arr[e--]);
    }

38. Merge Intervals- Overlapping Intervals

39. Continuous Subarray Sum - Divisible by k (size>=2) - 523 LeetCode
    

40.  Arithmetic Slices - Contiguous A.P. Subarray total count 
      int numberOfArithmeticSlices(vector<int>& nums)
    {
        int k=0,ans=0,n=nums.size();
       for(int i=1; i<n-1; i++)
       {
           if(nums[i]-nums[i-1]==nums[i+1]-nums[i])
           {
               ans += k+1; 
                 k++;  // subarray increased by one contiguous array 
           }
           else  k=0;
       }
        return ans ;
    }

41. Count Numbers with Unique Digits
// Input: n = 2  Output: 91
    //   excluding 11,22,33,44,55,66,77,88,99
  int countNumbersWithUniqueDigits(int n) 
    {
        if(n==0) return 1 ;
       int UniqueDigits=9,num_avail = 9,res=10;
        while(n-->1  and num_avail>0)
        {
            UniqueDigits *= num_avail--;
               res += UniqueDigits;
        }
        return res;
    }

42. Maximum Product Subarray
    // Kadene's and Reverse Kadane's 
    // take both Positive and Negative as both can increase the ans 
   //  0 always decrese the ans so leave it  
 long long maxProduct(vector<int> nums, int n) 
    {
        long long maxpro=INT_MIN,pro=1;
        for(int i=0 ; i<n ;i++)
         {
                  pro *= nums[i];
                  maxpro = max(maxpro,pro);
                  if(nums[i]==0) pro =1 ;
         }
         
         long long maxpro1=INT_MIN;pro=1;
        for(int i=n-1 ; i>=0 ;i--)
         {
                  pro *= nums[i];
                  maxpro1 = max(maxpro1,pro);
                  if(nums[i]==0) pro =1;
         }
         return max(maxpro1,maxpro);
    }

43. Reverse Bits in an  32 bit Unsinged integer
     uint32_t reverseBits(uint32_t X) 
    {
        long long ans=0,t=31; //  31 cycle 
        while(t--)
        {
            if(X&1) ans |= 1; // if last bit is 1 make ans first bit 1
              X>>=1; ans<<=1;
        }
         if(X&1) ans |= 1;  // checking last bit
        return ans;
    }

44.Counting Bits in every no. in [0,n] //  TC->O(n) SC->O(1)  
    
     vector<int> countBits(int n) 
    {
         vector<int> ans(n+1); //  pre declarartion for 0 to n
        for(int i=0 ; i<=n ; i++)
        {
            if(i<2) ans[i] = i; // saving bits 0 ,1 for record
            else
            {
                if(i&1)  // checking even odd 
                    ans[i] = (ans[i>>1]+1) ;  
                // if odd then it must have more bit than it's
                      //  right shifted element i/2
                // right shift already present in  array
                else
               ans[i] = ans[i>>1] ;
             // dont pushback if size is pre declared
            }
        }
        return ans ; 
    }


45. int twoCitySchedCost(vector<vector<int>>& costs)
    {
         // Leetcode Daily Challenge Optimized Solution 
         // Use of lambda Function it is faster than  Comparater
        //  Greedy Approach  // sorting according to Difference
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int n = costs.size() / 2;
        int res = 0;
        for (int i = 0; i < n; i++){
            res += costs[i][0] + costs[i + n][1];
        }
        return res;
    }

46. Pair Sum -Code Ninja (2Sum) All pair 
    
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
     sort(arr.begin(),arr.end());
     vector<vector<int>> ans;
     unordered_map <int,int> hash;
      int  n = arr.size();
        for(int i=0 ;i<n ;i++)
        { 
            if(hash.count(s-arr[i]))
            {
                int ct = hash[s-arr[i]];
                    while(ct--)
                ans.push_back({s-arr[i],arr[i]});   
            }
               hash[arr[i]]++;
        }
     sort(ans.begin(),ans.end());
    return ans;
} 

47. First Missing Positive Integer in An Array (Known as MEX)
    // hash Table - TC-O(n) SC - O(1) // LEETCODE Hard
    int firstMissingPositive(vector<int>& arr)
    {
         int  n =arr.size(),ind;
         for(int i=0 ;i<n; i++)
             if(arr[i]<=0) 
                 arr[i] = n+2; // marking all  -ve integer as positive
        // storing value is greater than n so that they not act as index
        
        for(int i=0 ;i<n; i++)
         {
             ind = abs(arr[i]);  // use as a index    
             ind--; // reducing  temp for use 1 at 0th index
             if(ind<n and arr[ind]>0)
                 arr[ind] *= -1;  // if positive integer is present mark -ve
         }
        for(int i=0 ;i<n ;i++)
            if(arr[i]>0) return i+1; 
       // if any integer is +ve it means that index is not present 
        
        return n+1; // if all present then we return N+1 
    }

48. Missing Number [0,n] range SIze of Array is n
        //TC-O(n) SC- O(1)
    int missingNumber(vector<int>& arr) 
    {
         vector<int> ans;
        int n=arr.size(); 
          for(int i=0 ; i<n ; i++)
          {
              if(arr[i]%(n+1)==n) continue; // ignoring n as index
              // beacause it is not valid for an array
              arr[arr[i]%(n+1)] += (n+1);   
          }          
          for(int i=0; i<n; i++)
               if(arr[i]/(n+1)<1) 
                   return i;
        // if all elements are present then it should be last element 
        return n;
    } 

49. Matrix Neighbour - Game of Life LeetCode 

     int Ncount (vector<vector<int>> &mat,int i,int j,int n,int m)
     {
         int ct=0;
         int s[] ={-1,0,1};
         // if(i-1>=0 and j-1>=0 and mat[i-1][j-1]==1)  ct++;
         // if(j-1>=0 and mat[i][j-1]==1) ct++;
         // if(i+1<n and j-1>=0 and mat[i+1][j-1]==1) ct++;
         // if(i-1>=0 and mat[i-1][j]==1) ct++;
         // if(i+1<n and mat[i+1][j]==1) ct++;
         // if(i-1>=0 and j+1<m and mat[i-1][j+1]==1) ct++;
         // if(j+1<m and mat[i][j+1]==1) ct++;
         // if(i+1<n and j+1<m and mat[i+1][j+1]==1) ct++;
         
         for(int k=0 ; k<3; k++)
         {
             for(int l=0; l<3; l++)
             {
                 if(s[k]==0 and s[l]==0) continue;
                 int newInd_i=i+s[k] , newInd_j=j+s[l];
                 if(newInd_i>=0 and newInd_j>=0 and newInd_i<n and newInd_j<m and mat[newInd_i][newInd_j])
                     ct++;
             }
         }
         return ct;
     }
         
public:
    void gameOfLife(vector<vector<int>>& mat) 
    {
        int  n = mat.size(),m = mat[0].size(),ct;
        vector<vector<int>> ans (n,vector<int> (m,0));
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0; j<m ; j++)
            {
                ct = Ncount(mat,i,j,n,m);
                if(ct<2) ans[i][j]=0;
                else if(ct==3) ans[i][j]=1;
                else if(ct>3) ans[i][j]= 0;
                else ans[i][j]= mat[i][j];
            }
        }
        mat = ans;
    }

50. 3Sum With Multiplicity  // Math P&C

     int threeSumMulti(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        int n = arr.size(),j,k,temp;
        unordered_map<int,int> hash ;
         for(int i=0; i<n; i++)
             hash[arr[i]]++;
         long long ans = 0 ,mod = 1e9+7;
        
        for(int i=0; i<n-2 ;i++ )
        {
            while(i>0 and  i<n-2 and arr[i-1]==arr[i]) i++; // skipping
             j=i+1; k=n-1;
                  while(j<k)
            {
                temp = arr[i]+arr[j]+arr[k];
                if(temp==target)
                {
                    if(arr[i]==arr[j] && arr[j]==arr[k]) // if all are same
                    {
                        long val=hash[arr[i]];
                           // cout<<val*val*val;
                       long long re=((val*(val-1))*(val-2))/6; 
    // taking  i,j,k such that i<j<k only has  one way which is nC3,  n= hash[arr[i]]
                        ans+=re;
                    }
                    else if(arr[i]==arr[j])  // if  First two are same 
                    {
                        long val=hash[arr[i]];
                       long long re=(val*(val-1))/2;    // nc2 ways only such that i<j
                        ans+=(re*hash[arr[k]]);
                    }
                    else if(arr[j]==arr[k])  // if last two are same
                    {
                        long val=hash[arr[j]];
                       long long re=1LL* (val*(val-1))/2;
                        ans+=(re*hash[arr[i]]);
                    }
                        // all are different total no. of pairs are nultiple
                    else if(arr[i]!=arr[j] && arr[i]!=arr[k] && arr[j]!=arr[k])
                    ans += hash[arr[i]]*hash[arr[j]]*hash[arr[k]];
                    ans %= mod;
                    
                    while(j<k and arr[j+1]==arr[j]) j++;  // skkiping 
                    while(j<k and arr[k-1]==arr[k]) k--;  // skkiping
                      j++; k--;
                }
                else if(temp > target) k--;
                else j++;           
            }    
        }
            return ans;
    }

51. Sort by Absolute Difference
    void sortABS(int A[],int N, int k)
    {
      stable_sort(A,A+N,[&k](int a,int b )
          {return abs(a-k)<abs(b-k);});
    }

52. Remove Duplicates from Sorted Array
     // skipping the duplicate Elements -- inplace approach
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),j=0,i=0;
        while(i<n)
        {
            while(i>0 and i<n and nums[i-1]==nums[i])
                  i++;
            if(i<n)
             nums[j++] = nums[i++];
        }
        return j;
    }

53. Subarray with given sum . return the 1 based indices 
        // sliding window
vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long sum = 0 ,i=0,j=0 ;
        for(i=0; i<n ;i++)
        {
            sum += arr[i] ;
             while(sum>s)
            {
                sum -= arr[j] ;
                j++;
            }
            
            if(sum==s)
                return {j+1,i+1} ;
        }
        return {-1} ;
    }

54 . Print/ generate all the subarrays Iteratively
        // complexity O(n(n+1)/2) ==  O(n^2)
 vector<vector<int>> generateSubarraysItr (vector<int> arr , int n )
{
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp ;
      for (int j = i; j < n; ++j)
       { 
          temp.push_back(arr[j]);
          ans.push_back   (temp);
      }
    }
    return ans ;
}

55. Find the number of subarrays having even sum;
    https://www.geeksforgeeks.org/find-number-subarrays-even-sum/

56. Find the Number of subarrays having odd sum ;
    
57. 

60. Maximize Number of 1s - Atmax M flips of zeros to 1

 int findZeroes(int nums[], int n, int m)
    {
        int j= 0 ;
        int ct = m ,len=0,mxlen=0;
        
        for(int i=0; i<n ; i++)
        {
            if(nums[i]==0)  ct--;
            if(ct<0 )
            {
                while(nums[j]!=0) j++;
                j++;
                  ct = 0 ;
            }
                len = i-j+1;
               mxlen = max(len,mxlen);
        } 
        return mxlen;
    } 
 
61. Total  Hamming Distance - No. of Pairs Having Difference in Corrosponding Bit
        //  count number of ones and zeros find no. of pairs  (0,1)
   int totalHammingDistance(vector<int>& nums) 
    {
        int n = nums.size(),ans=0,no_ones;
        for(int i=0; i<32 ; i++) // loop for every bit
        {
            no_ones =0 ;
            for(int j=0; j<n; j++)  // loop for every 
            {
                if(nums[j] & 1) 
                    no_ones++;
                
                nums[j] >>= 1 ; // Dropping every time last bit
            }
            ans += no_ones * (n-no_ones) ;
        }
        return ans ;
    }

62 . Majority Element II  - count > n/3
    // Moore's Volting aLGO
 vector<int> majorityElement(vector<int>& nums) 
    {
        int x(-1), y(-1), cx(0), cy(0) , n = nums.size();
        vector<int> ans ;
        
        for(int it  : nums)
        {
            if(it==x)  cx++; // IF it  matches 
            else if(it==y) cy++;
            else if(!cx) x = it , cx =1;
            else if(!cy) y = it,  cy =1;
            else  cx-- , cy-- ; 
        }
        
        cx=0 , cy = 0;
        for(int it : nums)
        {
            if(it == x) cx++;
            else if(it == y) cy++ ;
        }
        
        if(cx > n/3) ans.push_back(x);
        if(cy > n/3) ans.push_back(y) ;
        return ans ;
    }

63. Longest Subarray with sum divisible by K 

    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        long long len, mxlen = 0,presum =0 ;   
         unordered_map<int,int> hash ; 
        
         hash[0] =  -1 ; // if subarry starts from index  
         // premise is if Divisible number occur Remainder repeats itself

        for(int i=0 ; i<n ;i++)
        {
              presum += arr[i] ;
              int rem = presum%k; 
            // store remainder in range of 0  to K-1 
              if(rem<0) rem += k; 
             
              if(hash.count(rem))
              {
                  len = i - hash[rem];
                  mxlen = max(mxlen,len);
              }
            else hash[rem] = i;
        }
        return mxlen;
    }

64. Total Number  of Subarray Sums Divisible by K - 974
     int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map <int,int> hash ;
         long long  ct=0,prefix=0,rem;
          hash[0]++; // Initially Sum=0, rem=0 , ct =1
        
        for(int it :  nums)
        {
             prefix += it ;
            rem = prefix%k ;
            // store remainder in range of 0  to K-1 
            if(rem<0) rem += k ;
            
            if(hash.count(rem))
                ct += hash[rem];  // number of sum cumulative 

           hash[rem]++;
        }
        return ct ;
    }

65. Total number of Suabarrays Having Sum 0 -Zero Sum Subarrays
    ll findSubarray(vector<ll> arr, int n )
    {
        long long ans =0,prefix = 0; 
        unordered_map<int,int> hash ;
         hash[0]  = 1 ; // in  starting the sum=0 and freq is 1 
        // here frequency count is important 
        // we  are going to encounter with cumulative frequency 
        for(int i =0 ; i<n ; i++)
        {
            prefix += arr[i] ;
            
            // every time prefix sum reapeats then 0 sum subarray found 
            if(hash.count(prefix)) 
                 ans += hash[prefix] ; 
            // every time we found in map we get new subbarays equal to its freq
            
            hash[prefix]++ ; //storing prefix sum in map  
        }
        return ans ;
    }

66. Total Number of -Subarray Sums Equal to K - 560
int subarraySum(vector<int>& nums, int k) 
    {
         int ans=0,prefix=0,n=nums.size(); 
         unordered_map<int,int> hash ;
             hash[0]++ ;
        for(int i=0; i<n ; i++)
        {
            prefix += nums[i] ;
             // every time (prefix-k) is found in map  sum k is found
            if(hash.count(prefix-k)) 
            {
                ans +=  hash[prefix-k] ;
       // cumulative frequency is added every reapeated freq give new subarray
            }
            hash[prefix]++ ;
        }
        return ans ;
    }

67. Longest Sub-Array with Sum Equal to K 
https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
     int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        int len,prefix=0,mxlen=0;
        unordered_map<int,int> hash ;
         hash[0] = -1;
     // in longest type question prefix= 0  at index -1 
        for(int i = 0; i<n ; i++) 
        {
             prefix += A[i];
             
            if(hash.count(prefix-k))
            {
                len = i - hash[prefix-k] ;
                mxlen = max(mxlen,len);
            }
            if(!hash.count(prefix)) hash[prefix] =  i  ;
        }
        return mxlen ;
    } 

68. Largest/Longest Subarray Having Sum Greater than k 
69. Longest Subarray Having Sum Less than K 

70. Sum of All subarrays - MAth 
long long subarraySum(long long a[], long long n)
    {
        long long mod=1000000007,sum=0 ;
        for(int i=0 ; i<n ;i++)
        {
            // Every number in the array at ith (1 based)
            // position would come (i)*(n-i+1) times
            sum += a[i]*(i+1)*(n-(i+1)+1);
            sum = sum%mod;
        }
        return sum ;
    }



71. Maximum product subset of an array 

 long long int findMaxProduct(vector<int>&a, int n)
    {
        long long pro=1,zero=0,mod=1000000007;
        int neg=0,mnmx = INT_MIN,flag=1;
        for(int i=0; i<n ; i++)
        {
            if(a[i]<0) 
            {
                neg++;
                mnmx = max(mnmx,a[i]);
            }
        }
        for(int  i=0 ; i<n ;  i++)
        {
            if(neg&1 and a[i]==mnmx and flag)
               {flag=0; continue;}
            if(a[i]==0) {
                zero++;
                continue ;
            }
             pro *= a[i];
             pro %= mod ;
        }
        // case only  contains zero 
        if(zero and pro==1 and neg==1 and a.size()==neg+zero) 
          pro = 0;
        if(a.size()==1 and neg) pro = a[0];
        return pro ;
    }

72. Find Original Array From Doubled Array  // Leetcode

 vector<int> findOriginalArray(vector<int>& nums) 
    {
        vector<int> ans ;
        map<int,int> hash ;
        for(int it : nums)
        {
            hash[it]++;
        }
        for(auto it : hash)
        {
            int k = it.first,n = it.second;  
            while(n--)
            {
                hash[k]--;
                if(hash[k*2]>0)
                {
                    ans.push_back(k);
                    hash[2*k]--;
                }
            }
        }
        if(2*ans.size()!=nums.size()) return {} ;
        return ans ;
    }

73.  Minimize XOR 
class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int n =0,num = num1,k,j=1<<30,ans=0;
        while(num2>0) 
        {
          num2= (num2&(num2-1));
            n++;
            // counting bits on  num2
        }
        while(num1>0) 
        {
          num1= (num1&(num1-1));
            k++;
            // counting bits  omn num1 
        }
        
        if(n>k)
        {
            n -= k; 
            j  =1 ;
            while(n>0)
            {
                if(num & j);
                else
                {
                    // setting n unset bits from left 
                    num |= j ;
                    n--;
                }
                j<<=1;
            }
            return num; 
        }  
        if(n==k) return num;
        while(n>0)
        {
            if(j&num)
            {
                // setting n unset bits from right
                ans += j;
                num ^= j ;
                n--;
            }
           j /= 2;
        }
        return ans ;
    }
};