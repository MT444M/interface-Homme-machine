#pragma once
class CPlateau
{
private:
    int m_taille;
    int m_pixel;  //taille des objets
    int m_nb_pierres;
    int** plateau;
    int m_posx;
    int m_posy;
public:

    CPlateau();
    CPlateau(int, int, int);
    ~CPlateau();


   /* Initialisation statique du plateau de jeu */
    void initialiser_plateau();
    /* Dessine le plateau de jeu à l'aide de cercles colorés */
    void dessiner_plateau();
    /* Intervertit deux pierres sur le plateau de jeu */
    void intervertir_pierres(int x1, int y1, int x2, int y2,int diametre);
    void intervertir_Objets(CPoint point);
   
    int getplateau(int, int);
    void remplir_plateau(int);
    int getTaille_x();
    int getPixel();
    int getNbr_p();
    int getPosx();
    int getPosy();



    /*
    void afficher_boite_dialogue() {
        // Affiche une boîte de dialogue pour personnaliser la taille du plateau et le nombre de pierres 
        int taille_x, taille_y, nb_pierres;
        std::cout << "Entrez la taille du plateau (x, y) : ";
        std::cin >> taille_x >> taille_y;
        std::cout << "Entrez le nombre de catégories de pierres : ";
        std::cin >> nb_pierres;
        this->taille_x = taille_x;
        this->taille_y = taille_y;
        this->nb_pierres = nb_pierres;
        initialiser_plateau();
    }
    */
   


};


