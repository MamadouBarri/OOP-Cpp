class Poignée
{
public:
    Poignée();
    void tourner();
    void relâcher();
    bool estTournée() const;

private:
    bool estTournée_;
};

Poignée::Poignée() : estTournée_(false) {}

void Poignée::tourner()
{
    estTournée_ = true;
}

void Poignée::relâcher()
{
    estTournée_ = false;
}

bool Poignée::estTournée() const
{
    return estTournée_;
}

class Porte
{
public:
    Poignée& poignée();

    void ouvrir();
    void fermer();
    bool estOuverte() const;

private:
    Poignée poignée_;
    bool estOuverte_;
};

Poignée& Porte::poignée()
{
    return poignée_;
}
void Porte::ouvrir()
{
    if (poignée_.estTournée())
        estOuverte_ = true;
    poignée_.relâcher();
}
void Porte::fermer()
{
    estOuverte_ = false;
    poignée_.relâcher();
}
bool Porte::estOuverte() const
{
    return estOuverte_;
}

int main()
{
    Porte porte;

    porte.poignée().tourner();
    porte.ouvrir();

    if (porte.estOuverte())
        cout << "Vous entrez dans la piece" << endl;
    else
        cout << "Impossible d'entrer; la porte est barree" << endl;

    return 0;
}