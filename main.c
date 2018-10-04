/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "cfg.h"

int
main(void)
{
	/* allocate memory for the cfg structure */
	struct cfgfile *cfg = malloc(sizeof(struct cfgfile));
	if(!cfgsetup(cfg, "settings.cfg"))
	{
		perror("failed to create cfg structure");
		cfgfree(cfg);
		exit(1);
	}
	char buffer[256];
	int val = cfggetvalue(cfg, "gnu/linux", buffer, sizeof(buffer));
	if (val == 1)
		puts(buffer);
	else
		puts("key not found");
	/* free cfg structure we allocated */
	cfgfree(cfg);
	return 0;
}
