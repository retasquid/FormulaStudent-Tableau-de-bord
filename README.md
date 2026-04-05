# 🏎️ PROJET FORMULA STUDENT - Système d'Affichage Temps Réel

Je suis fier de vous présenter notre travail réalisé dans le cadre du projet Formula Student à l'IUT Lyon 1 Villeurbanne Gratte-Ciel !

# 📍 Contexte :
Dans cette compétition automobile étudiante, plusieurs spécialités et groupes collaborent pour concevoir un véhicule de course. Matthia Pretotto et moi avons travaillé sur le système d'affichage des données du véhicule.

# ⚙️ Objectif du projet :
Développer un système capable d'acquérir, traiter et afficher en temps réel les données du tableau de bord via le bus CAN de la voiture de course.

# 📊 Fonctionnalités implémentées :
• Vitesse instantanée du véhicule
• Régime moteur (RPM)
• Heure actuelle
• Tension batterie
• Position GPS du véhicule

# 🛠️ Technologies employées :
Le projet se base sur un microcontrôleur 8 bits PIC18F27Q84 et un transceiver CAN pour interfacer le bus CAN. Le software a été réalisé en C depuis l'IDE MPLABX avec le plugin MCC pour simplifier la configuration des périphériques. Nous avons également conçu la carte électronique puis nous l'avons fait imprimer par un professionnel.

# 💡 Défis techniques relevés :
Les contraintes principales du projet étaient de réussir à rafraîchir rapidement l'écran malgré les limitations du microcontrôleur PIC et d'assurer une réception fiable des données provenant du bus CAN. Pour ce faire, nous avons développé des bibliothèques optimisées pour interagir efficacement avec le bus CAN et accélérer le calcul des jauges de l'écran, atteignant ainsi un taux de rafraîchissement d'environ 3Hz.

Merci à Mr. Ismael Bakiri et Mr. Anthony Chaussat pour leur encadrement et leur soutien tout au long de ce projet.
