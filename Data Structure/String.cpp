#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#include<malloc.h>
#include<string.h>

//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;


typedef struct{
    char *ch;  //���Ƿǿմ����򰴴�������ռ䣬����chΪNULL
    int length; //���ĳ���
}String;

//--------�����������ĺ���ԭ��˵��--------

//����һ����ֵ����chars�Ĵ�
Status StrAssign(String &T, char *chars){
    if(T.ch)
        free(T.ch);
    int i;
    for(i = 0; *(chars+i); ++i){}
    if(!i){
        cout<<"���ַ���"<<endl;
        T.ch = NULL;
        T.length = 0;
    }else{
        if(!(T.ch = (char *)malloc(i * sizeof(char))))
            exit(OVERFLOW);
        int j;
        for(j = 0; j < i; j++){
            T.ch[j] = chars[j];
            T.length = i;
        }
        T.ch[T.length] = '\0';
    }
    return OK;
}//StrAssign

//���ش���Ԫ�ظ�����������
int StrLength(String S){
    return S.length;
}//StrLength

//�ַ����Ƚϣ���S>T,�򷵻�>0;��S=T���򷵻�=0����S<T���򷵻�<0;
int StrCompare(String S, String T){
    int i;
    for(i = 0; i < S.length && i < T.length; ++i)
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;
}
//����S���
Status ClearString(String &S){
    if(S.ch){
        free(S.ch);
        S.ch = NULL;
    }
    S.length = 0;
    return OK;
}//ClearString

//��T������S1��S2���Ӷ��ɵ��´�
Status Concat(String &T, String S1, String S2){
    if(T.ch)
        free(T.ch); //�ͷžɿռ�
    if(!(T.ch = (char*)malloc((S1.length + S2.length) * sizeof(char))))
        exit(OVERFLOW);
    int i;
    for(i = 0; i < S1.length; i++)
        T.ch[i] = S1.ch[i];
    T.length = S1.length + S2.length;
    int j;
    for( i = 0, j = S1.length; j < T.length; j++, i++)
        T.ch[j] = S2.ch[i];
    T.ch[T.length] = '\0';
    return OK;
}//Concat

//��ʼ��������S���ڣ�1<=pos<=StrLength(S) �� 0<=len<=StrLength(S)-pos+1
//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status SubString(String &Sub, String S, int pos, int len){
    if(pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
        return ERROR;
    if(Sub.ch)
        free(Sub.ch);
    if(!len){
        cout<<"Sub�����ڣ�"<<endl;
        Sub.ch = NULL;
        Sub.length = 0;
    }else{
        Sub.ch = (char *)malloc(len * sizeof(char));
        int i;
        for(i = 0; i < len; i++){
            Sub.ch[i] = S.ch [pos + i - 1];
            Sub.length = len;
        }
        S.ch[S.length] = '\0';
        return OK;
    }
    return OK;
}//SubSting

//�п�
Status StrEmpty(String S){
    if(S.length == 0)
        return TRUE;
    else
        return FALSE;
}//StrEmpty

//������
Status StrCopy(String &T, String S){
    if(!(T.ch = (char*)malloc(S.length * sizeof(char))))
        exit(OVERFLOW);
    T.ch = S.ch;
    T.length = S.length;
    return OK;
}//StrCopy

//������S�д��ںʹ�T��ͬ���Ӵ����򷵻����������е�
//��pos���ַ�֮��ĵ�һ�γ��ֵ�λ�ã�������ֵΪ0
Status Index(String S, String T, int pos){
    if(pos >= 0){
        String Sub;
        int n, m;
        n = StrLength(S);
        m = StrLength(T);
        int i = pos;
        while(i <= (n-m+1)){
            SubString(Sub, S, i, m);
            if(StrCompare(Sub, T) != 0)
                ++i;
            else
                return i;
        }//while
    }//if
    return 0;
}//Index

//��ʼ��������S���ڣ�1<=pos<=StrLength(S)+1
//����������ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
Status StrInsert(String &S, int pos, String T){
    if(pos < 1 || pos > S.length + 1) //pos���Ϸ�
        return ERROR;
    if(T.length){  //T�ǿգ������·���ռ䣬����T
        if(!(S.ch = (char *)realloc(S.ch,(S.length + T.length) * sizeof(char))))
            exit(OVERFLOW);
        int i;
        for(i = S.length-1; i >= pos-1; --i) //Ϊ����T���ڳ�λ��
            S.ch[i+T.length] = S.ch[i];
        for(i = 0; i < T.length; i++) //����T
            S.ch[pos+i] = T.ch[i];
        S.length += T.length;
        S.ch[S.length] = '\0';
    }
    return OK;
}//StrInsert

//��ʼ��������S���ڣ�1<=pos<=StrLength(S)-len+1
//����������Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
Status StrDelete(String &S, int pos, int len){
    if(pos < 1 || pos > (StrLength(S)-len+1)) //pos���Ϸ�
        return ERROR;
    if(S.length){  //T�ǿգ������·���ռ䣬����T
        int i;
        for(i=pos-1; i < (StrLength(S)-len+1); i++)
            S.ch[i] = S.ch[len+i];
        S.length -= len;
        S.ch[S.length] = '\0';
    }
    return OK;
}//StrInsert

//��ʼ��������S,T,V���ڣ�T�Ƿǿմ�
//�����������V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
Status Replace(String &S, String T, String V){
    int i;
    for(i = 0; i < (StrLength(S)-StrLength(T)); i++){
        int j = Index(S, T , 0);
        if(j){
            StrDelete(S, j, StrLength(T));
            StrInsert(S, j-1, V);
        }
    }
    return OK;
}//Replace

//���ٴ�
Status DestroyString(String &S){
    if(!S.ch)
        cout<<"�ַ��������ڣ�����Ҫ���٣�"<<endl;
    else{
        free(S.ch);
        S.ch = NULL;
        S.length = 0;
        cout<<"�ַ������ٳɹ���"<<endl;
    }
    return OK;
}//DestroyString




int main(){
    String S1,S2, T, Sub;
    char str1[] = {"aaa"};
    char str2[] = {"bbb"};
    StrAssign(S1, str1); //�����ַ���
    StrAssign(S2, str2);
    cout<<"�ַ���S1Ϊ��"<<S1.ch<<endl;//����ַ���
    cout<<"�ַ���S2Ϊ��"<<S2.ch<<endl;
    Concat(T, S1, S2);
    cout<<"S1��S2���Ӻϲ����ַ���TΪ��"<<T.ch<<endl;
    cout<<"T�ַ����ĳ���Ϊ��"<<StrLength(T)<<endl;
    cout<<"�ַ���S1��S2�Ƚϣ�";
    if(StrCompare(S1, S2) < 0)
        cout<<"S1 < S2"<<endl;
    else if(StrCompare(S1, S2) == 0)
        cout<<"S1 = S2"<<endl;
    else
        cout<<"S1 > S2"<<endl;
    SubString(Sub, T, 2, 3);
    cout<<"ȡT�ĵڶ����ַ���ʼ����Ϊ3���ַ���SubΪ��"<<Sub.ch<<endl;
    if(StrEmpty(Sub))
        cout<<"Sub�ַ���Ϊ�գ�"<<endl;
    else
        cout<<"Sub�ַ�����Ϊ�գ�"<<endl;
    StrCopy(Sub, T);
    cout<<"����T�ַ�����Sub��"<<Sub.ch<<endl;
    StrInsert(Sub, 3, S2);
    cout<<"�ڵ�4λ֮ǰ�����ַ���S2��"<<Sub.ch<<endl;
    cout<<"Sub�ַ����ĳ���Ϊ��"<<StrLength(Sub)<<endl;
    StrDelete(Sub, 4 , 3);
    cout<<"ɾ���ӵ�4���ַ����3λ�ַ���"<<Sub.ch<<endl;
    cout<<"Sub�ַ����ĳ���Ϊ��"<<StrLength(Sub)<<endl;
     StrInsert(Sub, 3, S2);
    cout<<"�ڵ�4λ֮ǰ�����ַ���S2��"<<Sub.ch<<endl;
    cout<<"Sub�ַ����ĳ���Ϊ��"<<StrLength(Sub)<<endl;
    Replace(Sub, S2, S1);
    cout<<"���ַ���Sub��������S2��ȵ��Ӵ��滻ΪS1��"<<Sub.ch<<endl;
    cout<<"����Sub�ַ�����S2��һ�γ���ʱ��λ�ã�"<<Index(Sub, S2, 0)<<endl;
    DestroyString(Sub);

    return 0;
}
