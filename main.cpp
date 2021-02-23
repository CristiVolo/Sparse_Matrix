#include <iostream>

// Elementele matricei rare sunt definite de urmatoarea structura
struct ElementMR
{
    unsigned int l, c;
    double val;
    ElementMR *legs;
    ElementMR *legd;
};

// Citirea elementelor matricei rare si crearea listei dublu inlantuite.
void citireMR(ElementMR *&rad, ElementMR *&ultim)
{
    unsigned int i, j, maxl=25, maxc=100;
    double v;
    ElementMR *p, *q;

    cout<<"Introduceti indexul de linie a primului element nenul(intre 1 si 25):";
    cin>>i;
    m++;

    cout<<"Introduceti indexul de coloana a primului element nenul(intre 1 si 100):";
    cin>>j;
    n++;

    cout<<"Introduceti valoarea primului element:";
    cin>>v;

    p=new ElementMR;
    p->l=i;
    p->c=j;
    p->val=v;

    nrEl++;
    if(nrEl==1)
    {
        p->legs=NULL;
        p->legd=NULL;
        ultim=p;
        rad=ultim;
    }

    char opt;
    cout<<"Alegeti optiunea (d/n):";
    cin>>opt;
    while(opt=='d')
    {
        do
        {
            cout<<"Introduceti indexul de linie al elementului nenul:";
            cin>>i;
        }while(i>maxl || i<0);

        do
        {
            cout<<"Introduceti indexul de coloana al elementului nenul:";
            cin>>j;
        }while(j>maxc || j<0);

        cout<<"Introduceti valoarea elementului nenul:";
        cin>>v;

        m++;
        n++;
        nrEl++;
        p=new ElementMR;
        p->l=i;
        p->c=j;
        p->val=v;
        p->legs=ultim;
        p->legd=NULL;
        ultim->legd=p;
        ultim=p;

        cout<<"Continuati?(d/n):";
        cin>>opt;

        // Sortare crescatoare a elementelor matricii in fct de valoare
        void aranjareMR(ElementMR *rad, ElementMR *ultim)
        {
            ElementMR *p, *q;
            int aux1, aux2;
            double aux3;
            for(p=rad; p!=ultim; p=p->legd)
            {
                for(q=p->legd; q!=NULL; q=q->legd)
                {
                    if(p->val > q->val)
                    {
                        aux1=p->l;
                        p->l=q->l;
                        q->l=aux1;

                        aux2=p->c;
                        p->c=q->c;
                        q->c=aux2;

                        aux3=p->val;
                        p->val=q->val;
                        q->val=aux3;
                    }
                }
            }
        }

        // Verifica daca matricea citita este rara sau nu
        void calcul_pondere()
        {
            float pondere;
            pondere=(float)nrEl/(m*n);
            if(pondere>=0.15 && pondere <= 3)
            {
                cout<<"Matricea data indeplineste conditiile de matrice rara";
            }
            else
            {
                cout<<"Matricea data NU indeplineste conditiile de matrice rara";
            }

        }

    }
}