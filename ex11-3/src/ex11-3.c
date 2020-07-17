#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct school_record SRec;
struct school_record{
    float gpa;
    int credit;
    char name[200];
    SRec *next;
    SRec *left, *right;
};

SRec *input(char *sname, SRec **p)
{
    FILE *sfp;
    SRec *head = NULL;
    SRec *tail = NULL;

    if((sfp = fopen(sname, "r")) == NULL){
        printf("�R�s�[���̃t�@�C�����I�[�v���o���܂���B\n");
        exit(1);
    }

    *p = (SRec *)malloc(sizeof(SRec) * 1); //�ŏ���1���̗̈���m�ۂ���
    if(*p == NULL){
        printf("�������̈悪�m�ۂł��܂���ł����B\n");
        free(*p);
        *p = NULL;
        exit(1);
    }
    (*p)->gpa = 0;
    (*p)->credit = 0;
    (*p)->name[0] = '\0';

    while(fscanf(sfp, "%f %d %s", &(*p)->gpa, &(*p)->credit, (*p)->name) != EOF){ // ���́��}�����̈�̊m�� �̌J��Ԃ�

        (*p)->next = NULL;
        if(tail == NULL){
            head = *p;
        }
        else{
            tail->next = *p;
        }
        tail = *p;

        *p = (*p)->next;

        *p = (SRec *)malloc(sizeof(SRec) * 1);
                if(*p == NULL){
                    printf("�������̈悪�m�ۂł��܂���ł����B\n");
                    free(*p);
                    *p = NULL;
                    exit(1);
                }
        (*p)->gpa = 0;
        (*p)->credit = 0;
        (*p)->name[0] = '\0';
    }
    free(*p); // 1�]���ɗ̈���m�ۂ��Ă���̂ŉ������

    fclose(sfp);

    return head;
}

int comp_gpa(const void * n1, const void * n2) //gpa
{
    if(((SRec*)n1) -> gpa < ((SRec*)n2) -> gpa){
        return -1;
    }
    else if(((SRec*)n1) -> gpa > ((SRec*)n2) -> gpa){
        return 1;
    }
    else{
        return 0;
    }
}

int comp_credit(const void * n1, const void * n2) //�P�ʐ�
{
    if(((SRec *)n1) -> credit < ((SRec *)n2) -> credit){
        return -1;
    }
    else if(((SRec *)n1) -> credit > ((SRec *)n2) -> credit){
        return 1;
    }
    else{
        return 0;
    }
}

int comp_name(const void * n1, const void * n2) //���O
{
    int i;
    i = strcmp(((SRec *)n1) -> name, ((SRec *)n2) -> name);
    return i;
}

SRec *listsort(SRec *head, int (*comp)(const void *, const void *))
{
    SRec *tree;
    SRec **p; //�񕪖ؗp
    SRec **q; //�A�����X�g�p

    tree = head;
    q = &(head->next);
    while(*q != NULL){
        p = &tree;
        while(*p != NULL){
            if(comp(*p, *q) > 0){
                p = &((*p)->left);
            }
            else{
                p = &((*p)->right);
            }
        }
        *p = *q;
        q = &((*q)->next);

    }

    return head;

}

SRec *sort(char *field, SRec *head)
{
    if(field[0] == 'g' && field[1] == 'p' && field[2] == 'a'){
        return listsort(head, comp_gpa);
    }
    else if(field[0] == 'c' && field[1] == 'r' && field[2] == 'e' && field[3] == 'd' && field[4] == 'i' && field[5] == 't'){
        return listsort(head, comp_credit);
    }
    else if(field[0] == 'n' && field[1] == 'a' && field[2] == 'm' && field[3] == 'e'){
        return listsort(head, comp_name);
    }
    else{
        printf("fuck\n");
        exit(1);
    }
}

int output(char *dname, SRec *sort_head)
{
    FILE *dfp;
    SRec *p;

    if((dfp = fopen(dname, "w")) == NULL){
        printf("�R�s�[��̃t�@�C�����I�[�v���o���܂���B\n");
        return 1;
    }

    p = sort_head;
    fprintf(dfp, "%.3f %d %s\n", p->gpa, p->credit, p->name); // �܂��擪���o��

    while(p->next != NULL){ //�c����o��
        p = p->next;
        fprintf(dfp, "%.3f %d %s\n", p->gpa, p->credit, p->name);
    }

    fclose(dfp);
    return 0;
}

void dump_list(SRec *list)
{
    if(list == NULL){
        return;
    }
    else{
        printf("(%5.3f %3d %10s) n:%p l:%p r:%p \n", list->gpa, list->credit, list->name, list, list->left, list->right);
        dump_list(list->next);
    }
}

void free_list(SRec *list)
{
    if(list == NULL){
        return;
    }
    else{
        free_list(list->next);
        free(list);
    }
}

int main(int argc, char *argv[])
{
    SRec *record;
    SRec *head, *sort_head;

    if (argc != 4){
        printf("�����̌�������������܂���B\n");
        return 1;
    }

    head = input(argv[2], &record);

    sort_head = sort(argv[1], head);

    output(argv[3], sort_head);

    dump_list(head);

    free_list(head);
    record = NULL;

    return 0;
}
