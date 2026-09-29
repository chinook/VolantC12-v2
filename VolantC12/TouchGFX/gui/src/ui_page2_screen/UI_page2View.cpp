#include <gui/ui_page2_screen/UI_page2View.hpp>

UI_page2View::UI_page2View()
{

}

void UI_page2View::setupScreen()
{
    UI_page2ViewBase::setupScreen();
}

void UI_page2View::tearDownScreen()
{
    UI_page2ViewBase::tearDownScreen();
}

void UI_page2View::change_screen(uint8_t screen)
{
	UI_page2ViewBase::handleKeyEvent(screen);
}

/* NOTE : la page 2 a ete redessinee dans le Designer. Les anciens widgets
 * power_text / efficiency_text / tsr_text n'existent plus (remplaces par des
 * TextArea statiques power_value, eff_value, tsr n'existe pas, etc., sans
 * champ wildcard). Ces trois fonctions ecrivaient donc dans des widgets
 * inexistants : le code ne compilait sur aucune cible et n'est jamais appele
 * (UI_page2Presenter::update_ui est entierement commente).
 * Elles sont laissees en no-op pour que le projet compile ; a recabler sur les
 * vrais widgets (et rendre ces widgets "wildcard" dans le Designer) quand la
 * page 2 recevra ses donnees. */
void UI_page2View::update_power(float power)
{
	(void)power;
}

void UI_page2View::update_efficiency(float eff)
{
	(void)eff;
}

void UI_page2View::update_tsr(float tsr)
{
	(void)tsr;
}
