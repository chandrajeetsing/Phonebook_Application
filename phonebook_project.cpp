#include <bits/stdc++.h>
using namespace std;

int menu();
int k = 0;

int partition2(vector<string> ans, int low, int high)
{
    string pivot = ans[high];

    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++)
    {

        if (ans[j] < pivot)
        {        // If current element is smaller than the pivot
            i++; // Increment index of smaller element
            swap(ans[i], ans[j]);
        }
    }
    swap(ans[i + 1], ans[high]);

    return (i + 1);
}

void quickSort2(vector<string> ans, int low, int high)
{
    if (low < high)
    {
        int pi = partition2(ans, low, high);
        quickSort2(ans, low, pi - 1);
        quickSort2(ans, pi + 1, high);
    }
}

int partition(string arr[], string arr2[], int low, int high)
{
    string pivot = arr[high];

    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {        // If current element is smaller than the pivot
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
            swap(arr2[i], arr2[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    swap(arr2[i + 1], arr2[high]);
    return (i + 1);
}

void quickSort(string arr[], string arr2[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, arr2, low, high);
        quickSort(arr, arr2, low, pi - 1);
        quickSort(arr, arr2, pi + 1, high);
    }
}

class TrieNode2
{
public:
    char data;
    TrieNode2 *children[10];
    bool isTerminal;

    TrieNode2(char ch)
    {
        data = ch;
        for (int i = 0; i < 10; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie2
{
public:
    TrieNode2 *root;

    Trie2()
    {
        root = new TrieNode2('\0');
    }

    void insertUtil(TrieNode2 *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - '0';
        TrieNode2 *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode2(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode2 *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - '0';
        TrieNode2 *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void printSuggestions(TrieNode2 *curr, vector<string> &temp, string &prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (int ch = 0; ch <= 9; ch++) // Iterate over possible digit indices 0-9
        {
            TrieNode2 *next = curr->children[ch];
            if (next != NULL)
            {
                prefix.push_back('0' + ch); // Convert integer index to character digit
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<string> suggestions(string &str)
    {
        TrieNode2 *prev = root;
        vector<string> output;
        string prefix = "";
        TrieNode2 *curr;

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);
            int index = lastch - '0'; // Convert character digit to integer index
            curr = prev->children[index];
            if (curr == NULL)
            {
                return output; // No suggestions if any part of the prefix is not found
            }
            prev = curr;
        }

        printSuggestions(prev, output, prefix);
        return output;
    }

    void deleteall()
    {
        for (int i = 0; i < 10; i++)
        {
            root->children[i] = NULL;
        }
    }
};

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = tolower(word[0]) - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(tolower(word[0]));
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = tolower(word[0]) - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string &prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<string> suggestions(string &str)
    {
        TrieNode *prev = root;
        vector<string> output;
        string prefix = "";
        TrieNode *curr;

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);
            curr = prev->children[lastch - 'a'];
            if (curr == NULL)
            {
                return output; // No suggestions if any part of the prefix is not found
            }
            prev = curr;
        }

        printSuggestions(prev, output, prefix);
        return output;
    }

    void deleteword(TrieNode* root,string word)
    {
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            curr=curr->children[word[i]-'a'];

        }
        curr->isTerminal=false;
    }

    void deleteutil(string word)
    {
        deleteword(root,word);


    }


             

    void deleteall()
    {
        for (int i = 0; i < 26; i++)
        {
            root->children[i] = NULL;
        }
    }
};

int main()
{
    Trie *t1 = new Trie;
    Trie2 *t2 = new Trie2;
    int selc = 0;
    string namer[100];
    string no[100];
    unordered_map<string, string> mp;
    unordered_map<string, string> mp2;

    do
    {
        selc = menu();

        if (selc == 1)
        { // Insert word
            string name, number;
            cout << "\n\n\t\t\t\tEnter name: ";
            cin >> name;
            cout << "\n\n\t\t\t\tEnter number: ";
            cin >> number;

            if (number.length() != 10)
            {
                cout << "\n\t\t\t\t Phone number must be exactly 10 digits long!" << endl;
                cout << "\n\n\t\t\t\t Press Enter for the menu...";
                cin.ignore();
                cin.get();
                system("cls");
                continue; // Skip the rest of the loop and return to the menu
            }
            if (t1->search(name) || t2->search(number))
            {
                cout << " \n\n\t\t\t\tContact already exists.\n";
                cout << "\n\n\t\t\t\t Press Enter for the menu...";
                cin.ignore();
                cin.get();
            }
            else
            {
                t1->insertWord(name);
                t2->insertWord(number);
                namer[k] = name;
                no[k] = number;
                mp[name] = number;
                mp2[number] = name;
                k++;
                cout << "\n\n\t\t\t\tContact added.\n";
                cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
                cin.ignore();
                cin.get();
            }
            system("cls");
        }

        else if (selc == 2)
        {
            int flag = 0;
            quickSort(namer, no, 0, k - 1);
            cout << "\n\n\n\n\n\n\n\n";
            for (int i = 0; i < k; i++)
            {
                if (namer[i] != "NULL")
                {
                    flag++;
                    cout << "\t\t\t\t Name: " << namer[i] << "\t\tPhone no: " << no[i] << endl;
                }
            }
            if (flag == 0)
                cout << "\n\n\t\t\t\t No contacts found...";
            cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
            cin.ignore(); // Wait for the user to press Enter before going back to the menu
            cin.get();
            system("cls");
        }
        // search by name
        else if (selc == 3)
        {
            string a;
            cin >> a;
            if (t1->search(a))
            {
                cout << a << " " << mp[a] << endl;
            }
            else
            {
                vector<string> ans = t1->suggestions(a);

                if (ans.empty())
                {
                    cout << "\n\n\t\t\t\tNo record found" << endl;
                    cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
                }
                else
                {
                    int n = ans.size();
                    quickSort2(ans, 0, n - 1);
                    for (int i = 0; i < n; i++)
                    {
                        cout << ans[i] << " " << mp[ans[i]] << endl;
                    }
                    cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
                }
                cin.ignore();
                cin.get();
                system("cls");
            }
        }

        // selec by number
        else if (selc == 4)
        {
            string a;
            cin >> a;

            // Check if exact match exists in Trie2
            if (t2->search(a))
            {
                cout << mp2[a] << " " << a << endl; // Output the number and associated name
                cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
            }
            else
            {
                // If exact match not found, get suggestions
                vector<string> ans = t2->suggestions(a);

                if (ans.empty())
                {
                    cout << "\n\n\t\t\t\tNo record found" << endl;
                    cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
                }
                else
                {
                    int n = ans.size();
                    quickSort2(ans, 0, n - 1); // Sort suggestions alphabetically
                    for (int i = 0; i < n; i++)
                    {
                        cout << mp2[ans[i]] << " " << ans[i] << endl; // Output number and associated name
                    }
                    cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
                }
                cin.ignore();
                cin.get();
                system("cls");
            }
        }

        //-----DELETE CONTACT------
        

        else if (selc == 6)
        {
            cout << "\n\n\n\t\t\t\t Phonebook application Closed";
            break;
        }

        else if (selc == 5)
        {
            k = 0;
            t1->deleteall();
            t2->deleteall();
            mp.clear();
            mp2.clear();
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t ALL CONTACTS DELETED SUCCESSFULLY";
            cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
            cin.ignore();
            cin.get();
            system("cls");
        }

        else
        {
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t INVALID CHOICE";
            cout << "\n\n\n\t\t\t\t Press Enter for the menu...";
            cin.ignore();
            cin.get();
            system("cls");
        }

        // Other options can be implemented similarly

    } while (true);
}

int menu()
{
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t|           PHONEBOOK APPLICATION            |\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t|             [1] Add Contacts               |\n";
    cout << "\t\t\t\t|             [2] Display all Contacts       |\n";
    cout << "\t\t\t\t|             [3] Search by Name             |\n";
    cout << "\t\t\t\t|             [4] Search by Number           |\n";
    cout << "\t\t\t\t|             [5] Delete All                 |\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t|             [6] Exit                       |\n";
    cout << "\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tEnter your choice: ";
    int a;
    cin >> a;
    // system("cls"); // Commented out to avoid platform dependency
    system("cls");
    return a;
}
