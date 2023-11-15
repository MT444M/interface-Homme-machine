#include "pch.h"
#include "CPlateau.h"

CPlateau::CPlateau()
{

    // Initialize default values for the class variables
    m_taille = 8;
    m_pixel = 70;
    m_nb_pierres = 6;
    m_posx = 100;
    m_posy = 100;

    //Initialisation à 0 des elements de Plateau
    initialiser_plateau();
}

 CPlateau::CPlateau(int taille_x, int pixel, int nb_pierres)
 {
     this->m_taille = taille_x;
     this->m_pixel = pixel;
     this->m_nb_pierres = nb_pierres;

    initialiser_plateau();
 }


 void CPlateau::initialiser_plateau() {
     /* Allouer de la mémoire pour le plateau */
     plateau = new int* [m_taille];
     for (int i = 0; i < m_taille; i++) {
         plateau[i] = new int[m_taille];
     }

     for (int i = 0; i < m_taille; i++)
         for (int j = 0; j < m_taille; j++)
             plateau[i][j] = 0;

     /* Initialisation aléatoire des pierres sur le plateau */
     srand(time(NULL));
     for (int i = 0; i < m_taille; i++) {
         for (int j = 0; j < m_taille; j++) {
             plateau[i][j] = rand() % m_nb_pierres;
         }
     }
 }

 void CPlateau::dessiner_plateau() {
     /* Dessiner les pierres sur le plateau à l'aide de cercles colorés */
     for (int i = 0; i < m_taille; i++) {
         for (int j = 0; j < m_taille; j++) {
             /* Code pour dessiner un cercle coloré en fonction de la couleur de la pierre */
             int couleur = plateau[i][j];
             /* ... */
         }
     }
 }

 /*
 void CPlateau::intervertir_pierres(int x1, int y1, int x2, int y2, int diametre) {
     // Convertir les coordonnées de la souris en coordonnées de la pierre dans la grille
     int x1_grid = (x1 - 100) / diametre;
     int y1_grid = (y1 - 100) / diametre;
     int x2_grid = (x2 - 100) / diametre;
     int y2_grid = (y2 - 100) / diametre;

     // Vérifier si les coordonnées sont valides
     if (x1_grid < 0 || x1_grid >= m_taille || y1_grid < 0 || y1_grid >= m_taille) {
         AfxMessageBox(_T("Coordonnées de la première pierre non valides."));
         return;
     }
     if (x2_grid < 0 || x2_grid >= m_taille || y2_grid < 0 || y2_grid >= m_taille) {
         AfxMessageBox(_T("Coordonnées de la deuxième pierre non valides."));
         return;
     }

     // Vérifier si les pierres sont adjacentes
     if (abs(x1_grid - x2_grid) > 1 || abs(y1_grid - y2_grid) > 1) {
         AfxMessageBox(_T("Les pierres sélectionnées ne sont pas adjacentes."));
         return;
     }

     // Intervertir les pierres
     int temp = plateau[x1_grid][y1_grid];
     plateau[x1_grid][y1_grid] = plateau[x2_grid][y2_grid];
     plateau[x2_grid][y2_grid] = temp;
 }
 */
 /*
 void CPlateau::intervertir_Objets(CPoint point)
 {
     // Récupérer les coordonnées du premier cercle cliqué
     int x1 = (point.x - 100) / 70;
     int y1 = (point.y - 100) / 70;

     // Vérifier si les coordonnées sont valides
     if (x1 < 0 || x1 >= m_taille || y1 < 0 || y1 >= m_taille) {
         return;
     }

     // Définir la zone de sécurité pour le premier cercle
     int x1_min = x1 * 70 + 100 - 10;
     int y1_min = y1 * 70 + 100 - 10;
     int x1_max = x1 * 70 + 100 + 10;
     int y1_max = y1 * 70 + 100 + 10;

     // Vérifier si le point cliqué est dans la zone de sécurité
     if (point.x < x1_min || point.x > x1_max || point.y < y1_min || point.y > y1_max) {
         return;
     }

     // Récupérer les coordonnées du deuxième cercle cliqué
     int x2 = (point.x - 100) / 70;
     int y2 = (point.y - 100) / 70;

     // Vérifier si les coordonnées sont valides
     if (x2 < 0 || x2 >= m_taille || y2 < 0 || y2 >= m_taille) {
         return;
     }

     // Définir la zone de sécurité pour le deuxième cercle
     int x2_min = x2 * 70 + 100 - 10;
     int y2_min = y2 * 70 + 100 - 10
         ;
     int x2_max = x2 * 70 + 100 + 10;
     int y2_max = y2 * 70 + 100 + 10;

    // Vérifier si le point cliqué est dans la zone de sécurité
    if (point.x < x2_min || point.x > x2_max || point.y < y2_min || point.y > y2_max) {
        return;
    }



    // Vérifier si les cercles sont adjacents
    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
        // Intervertir les cercles
        CProjetDoc* pDoc = GetDocument();
        int temp = pDoc->pPlateauDoc->getCouleur(x1, y1);
        pDoc->pPlateauDoc->setCouleur(x1, y1, pDoc->pPlateauDoc->getCouleur(x2, y2));
        pDoc->pPlateauDoc->setCouleur(x2, y2, temp);
    }
 }
 */

 void CPlateau::intervertir_Objets(CPoint point) {
     for (int i = 0; i < m_taille; i++) {
         for (int j = 0; j < m_taille; j++) {

             // Définir les cases du plateau: 8x8 cases de tailles m_pixelxm_pixel
             //1er case
             int x1_min = m_posx + i*m_pixel;
             int y1_min = m_posy + j*m_pixel;
             int x1_max = m_posx + (i+1)*m_pixel;
             int y1_max = m_posy + (i+1)*m_pixel;

             // Récupérer les coordonnées du premier cercle cliqué
             int x1 = point.x;
             int y1 = point.y ;
             // Récupérer les coordonnées du premier cercle cliqué
            // int x2 = point.x;
             //int y2 = point.y;

             // Vérifier si le point cliqué est dans la case 1
             if (x1 < x1_min || x1 > x1_max || y1 < y1_min || y1> y1_max) {
                 return;
             }

             //2ieme case : toutes les cases ajdecantes à la première
             // à compléter
             // 
           

             // Récupérer les coordonnées du deuxième cercle cliqué
             int x2 = point.x;
             int y2 = point.y;
             // Vérifier si le 2ième click est sur la 2ième case






         }
     }

 }


 int CPlateau::getTaille_x() {
     return m_taille;
 }

 int CPlateau::getPixel() {
     return m_pixel;
 }

 int CPlateau::getNbr_p() {
     return m_nb_pierres;
 }

 int CPlateau::getPosx() {
     return m_posx;
 }

 int CPlateau::getPosy() {
     return m_posy;
 }

 int CPlateau::getplateau(int i, int j)
 {
     return plateau[i][j];
 }
 
 void CPlateau::remplir_plateau(int k)
 {
     for (int i = 0; i < m_taille; i++) {
         for (int j = 0; j < m_taille; j++) {
             plateau[i][j] = k ;
         }
     }
 }
 CPlateau::~CPlateau() {
     /* Libérer la mémoire allouée pour le plateau */
     for(int i = 0; i < m_taille; i++) {
         delete[] plateau[i];
     }
     delete[] plateau;
 }

