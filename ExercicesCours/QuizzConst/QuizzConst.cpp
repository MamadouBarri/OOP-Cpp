class Poign�e
{
public:
    Poign�e();
    void tourner();
    void rel�cher();
    bool estTourn�e() const;

private:
    bool estTourn�e_;
};

Poign�e::Poign�e() : estTourn�e_(false) {}

void Poign�e::tourner()
{
    estTourn�e_ = true;
}

void Poign�e::rel�cher()
{
    estTourn�e_ = false;
}

bool Poign�e::estTourn�e() const
{
    return estTourn�e_;
}

class Porte
{
public:
    Poign�e& poign�e();

    void ouvrir();
    void fermer();
    bool estOuverte() const;

private:
    Poign�e poign�e_;
    bool estOuverte_;
};

Poign�e& Porte::poign�e()
{
    return poign�e_;
}
void Porte::ouvrir()
{
    if (poign�e_.estTourn�e())
        estOuverte_ = true;
    poign�e_.rel�cher();
}
void Porte::fermer()
{
    estOuverte_ = false;
    poign�e_.rel�cher();
}
bool Porte::estOuverte() const
{
    return estOuverte_;
}

int main()
{
    Porte porte;

    porte.poign�e().tourner();
    porte.ouvrir();

    if (porte.estOuverte())
        cout << "Vous entrez dans la piece" << endl;
    else
        cout << "Impossible d'entrer; la porte est barree" << endl;

    return 0;
}