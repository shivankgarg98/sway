#include <strings.h>
#include "sway/commands.h"
#include "sway/config.h"
#include "sway/tree/arrange.h"

struct cmd_results *cmd_tab_titles(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "tab_titles", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	if (strcasecmp(argv[0], "show") == 0) {
		config->hide_tab_titles = false;
	} else if (strcasecmp(argv[0], "hide") == 0) {
		config->hide_tab_titles = true;
	} else if (strcasecmp(argv[0], "toggle") == 0) {
		config->hide_tab_titles = !config->hide_tab_titles;
	} else {
		return cmd_results_new(CMD_INVALID,
			"Expected 'tab_titles show|hide|toggle'");
	}

	arrange_root();

	return cmd_results_new(CMD_SUCCESS, NULL);
}
