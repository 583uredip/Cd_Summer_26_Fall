#include<iostream>
#include<cstring>
using namespace std;

bool isNumeric(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if((int)str[i] < 48 || (int)str[i] > 57)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char input[200];
    cout << "Enter Your Input: ";
    cin.getline(input, 200);

    string keyword[12] = {
        "int","float","if","else","while",
        "return","char","double","main","void",
        "for","stack"
    };
    int keyword_count = 12;

    int id_start_chars[53] = {
        97,98,99,100,101,102,103,104,105,106,107,108,109,
        110,111,112,113,114,115,116,117,118,119,120,121,122,
        65,66,67,68,69,70,71,72,73,74,75,76,77,
        78,79,80,81,82,83,84,85,86,87,88,89,90,
        95
    };
    int id_start_count = 53;

    int id_chars[63] = {
        97,98,99,100,101,102,103,104,105,106,107,108,109,
        110,111,112,113,114,115,116,117,118,119,120,121,122,
        65,66,67,68,69,70,71,72,73,74,75,76,77,
        78,79,80,81,82,83,84,85,86,87,88,89,90,
        48,49,50,51,52,53,54,55,56,57,
        95
    };
    int id_chars_count = 63;

    int op_symbols[11] = {43,45,42,47,37,61,60,62,33,38,124};
    int op_sym_count = 11;

    int punc_symbols[9] = {40,41,123,125,91,93,59,44,46};
    int punc_sym_count = 9;

    char keywords_found[30][20];
    char identifiers[30][20];
    char int_constants[30][20];
    char float_constants[30][20];
    char operators[30][5];
    char punctuations[30][5];
    char errors[30][5];

    int kw_count=0, id_count=0, int_count=0;
    int fl_count=0, op_count=0, punc_count=0, err_count=0;

    char *start, *end;
    start = end = input;

    while(*end != '\0')
    {
        if((int)*end == 32 || (int)*end == 9 || (int)*end == 10)
        {
            end++;
            continue;
        }

        bool is_id_start = false;
        for(int i = 0; i < id_start_count; i++)
        {
            if((int)*end == id_start_chars[i])
            {
                is_id_start = true;
                break;
            }
        }

        if(is_id_start)
        {
            start = end;

            bool in_id = true;
            while(in_id && *end != '\0')
            {
                in_id = false;
                for(int i = 0; i < id_chars_count; i++)
                {
                    if((int)*end == id_chars[i])
                    {
                        in_id = true;
                        break;
                    }
                }
                if(in_id) end++;
            }

            char temp[20];
            strncpy(temp, start, end-start);
            temp[end-start] = '\0';

            bool found = false;
            for(int i = 0; i < keyword_count; i++)
            {
                if(keyword[i] == string(temp))
                {
                    strcpy(keywords_found[kw_count++], temp);
                    found = true;
                    break;
                }
            }
            if(!found)
                strcpy(identifiers[id_count++], temp);
        }

        else
        {
            bool next_is_digit = ((int)*(end+1) >= 48 && (int)*(end+1) <= 57);
            bool cur_is_digit  = ((int)*end >= 48 && (int)*end <= 57);

            if((int)*end == 45 && next_is_digit)
            {
                start = end;
                end++;

                while((int)*end >= 48 && (int)*end <= 57) end++;

                bool isFloat = false;
                if((int)*end == 46)
                {
                    isFloat = true;
                    end++;
                    while((int)*end >= 48 && (int)*end <= 57) end++;
                }

                char temp[20];
                strncpy(temp, start, end-start);
                temp[end-start] = '\0';

                if(isNumeric(string(temp+1)))
                    strcpy(int_constants[int_count++], temp);
                else
                    strcpy(float_constants[fl_count++], temp);
            }

            else if(cur_is_digit)
            {
                start = end;

                while((int)*end >= 48 && (int)*end <= 57) end++;

                bool isFloat = false;
                if((int)*end == 46)
                {
                    isFloat = true;
                    end++;
                    while((int)*end >= 48 && (int)*end <= 57) end++;
                }

                char temp[20];
                strncpy(temp, start, end-start);
                temp[end-start] = '\0';

                if(isFloat)
                    strcpy(float_constants[fl_count++], temp);
                else
                    strcpy(int_constants[int_count++], temp);
            }

            else
            {
                bool is_op = false;
                for(int i = 0; i < op_sym_count; i++)
                {
                    if((int)*end == op_symbols[i])
                    {
                        is_op = true;
                        break;
                    }
                }

                if(is_op)
                {
                    char temp[5];
                    temp[0] = *end;
                    temp[1] = '\0';

                    if((((int)*end==61||(int)*end==33||(int)*end==60||
                         (int)*end==62||(int)*end==43||(int)*end==45)
                         && (int)*(end+1)==61)
                       || ((int)*end==43 && (int)*(end+1)==43)
                       || ((int)*end==45 && (int)*(end+1)==45))
                    {
                        temp[1] = *(end+1);
                        temp[2] = '\0';
                        end++;
                    }

                    strcpy(operators[op_count++], temp);
                    end++;
                }

                else
                {
                    bool is_punc = false;
                    for(int i = 0; i < punc_sym_count; i++)
                    {
                        if((int)*end == punc_symbols[i])
                        {
                            is_punc = true;
                            break;
                        }
                    }

                    if(is_punc)
                    {
                        punctuations[punc_count][0] = *end;
                        punctuations[punc_count][1] = '\0';
                        punc_count++;
                        end++;
                    }
                    else
                    {
                        errors[err_count][0] = *end;
                        errors[err_count][1] = '\0';
                        err_count++;
                        end++;
                    }
                }
            }
        }
    }

    cout << "\n========== LEXICAL ANALYSIS RESULT ==========\n";

    cout << "\n[Keywords]          (" << kw_count << "): ";
    for(int i=0; i<kw_count; i++) cout << keywords_found[i] << " ";

    cout << "\n[Identifiers]       (" << id_count << "): ";
    for(int i=0; i<id_count; i++) cout << identifiers[i] << " ";

    cout << "\n[Integer Constants] (" << int_count << "): ";
    for(int i=0; i<int_count; i++) cout << int_constants[i] << " ";

    cout << "\n[Float Constants]   (" << fl_count << "): ";
    for(int i=0; i<fl_count; i++) cout << float_constants[i] << " ";

    cout << "\n[Operators]         (" << op_count << "): ";
    for(int i=0; i<op_count; i++) cout << operators[i] << " ";

    cout << "\n[Punctuations]      (" << punc_count << "): ";
    for(int i=0; i<punc_count; i++) cout << punctuations[i] << " ";

    if(err_count > 0)
    {
        cout << "\n[Lexical Errors]    (" << err_count << "): ";
        for(int i=0; i<err_count; i++) cout << errors[i] << " ";
    }

    cout << "\n=============================================\n";
    return 0;
}
