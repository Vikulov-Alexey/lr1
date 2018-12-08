#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static char *whom = "module";
module_param(whom, charp, 0);

static int howmany = 1;
module_param(howmany, int, 0);

static int __init hello_init(void)
{
	int i;

	for (i = 0; i < howmany; i++)
		pr_alert("(%d) Init %s\n", i, whom);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_alert("Exit %s\n", whom);
}

module_init(hello_init);
module_exit(hello_exit);
