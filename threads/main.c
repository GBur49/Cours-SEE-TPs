#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/kernel/thread.h>
#include <zephyr/kernel/thread_stack.h>

#define STACK_SIZE 1024
#define PRIORITY   5
#define ITERATIONS 10



/* TODO: reserve one stack per thread */
k_thread_stack_t stack_ping[STACK_SIZE];
k_thread_stack_t stack_pong[STACK_SIZE];


/* TODO: declare one thread control block per thread */


/* TODO: q2 - declare the semaphores */

static void ping_entry(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	for (int i = 0; i < ITERATIONS; i++) {
		/* TODO: q2 - wait for your turn */

		printk("Ping\n");

		/* TODO: q2 - hand the turn over */
	}
}

static void pong_entry(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	for (int i = 0; i < ITERATIONS; i++) {
		/* TODO: q2 - wait for your turn */
		

		
		printk("Pong\n");

		/* TODO: q2 - hand the turn over */
	}
}

int main(void)
{
	
	struct k_thread thread_struct_ping = {};
	struct k_thread thread_struct_pong = {};
	struct k_mutex my_mutex;

	k_mutex_init(&my_mutex);
	//int p1,p2,p3;

	printk("=== Threads lab ===\n");
	
	/* TODO: create both threads */
	k_thread_create(&thread_struct_ping, stack_ping, K_THREAD_STACK_SIZEOF(stack_ping) ,ping_entry, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
	k_thread_create(&thread_struct_pong, stack_pong, K_THREAD_STACK_SIZEOF(stack_pong) ,pong_entry, NULL, NULL, NULL, 1, 0, K_NO_WAIT);

	k_thread_join(&thread_struct_ping, K_FOREVER);
	k_thread_join(&thread_struct_pong, K_FOREVER);
/*
	if(k_mutex_lock(&my_mutex, K_MSEC(100))==0){
		k_thread_join(&thread_struct_ping, K_FOREVER);
	}
	else{
		printk("Cannot lock mutex\n");
	}
	if(k_mutex_lock(&my_mutex, K_MSEC(100))==0){
		k_thread_join(&thread_struct_pong, K_FOREVER);
	}
	else{
		printk("Cannot lock mutex\n");
	}
*/	
	
	/* TODO: wait for both threads to finish */



	printk("=== Done ===\n");
	return 0;
}
