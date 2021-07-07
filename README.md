# philosophers @ 42

## GOALS
* Learn how to make threads
* How to work on the same memory space
* Notions : mutex, semaphore and shared memory

## RULES
* Coded in C, respecting the norm
* n philosophers are sitting at a table and have one of three state : eat, think, sleep
* philoserphers share one memory space (spaghetti bowl)
* a philosopher must eat with two forks, one for each hand		?? Two forks to make ??
* philosophers should not die (starving)
* every philosopher need to eat
* a philosopher doesn't talk to another and dont know when another die		?? Some wait for to access mutex ??
* when finish eating, he goes to sleep		?? when he used mutex, change state for waiting ??
* sleep -> think		?? from waiting to wait free mutex ??
* simulation stop when a philosopher die

## TECHNICAL
* Options for ./exec : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [nbr_philo_must_eat]
* number_of_philosophers : is the number of philosophers and also the number of forks
* time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies
* time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
* time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
* nbr_philo_must_eat: argument is optional, if all philosophers eat at least ’nbr_philo_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

## CODE
* Each philosopher should be given a number from 1 to ’number_of_philosophers’.
* Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with number N is seated between philosopher N - 1 and philosopher N + 1
* Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in mil- liseconds)
	* timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating
	* timestamp_in_ms X is sleeping
	* timestamp_in_ms X is thinking
	* timestamp_in_ms X died
* The status printed should not be scrambled or intertwined with another philosopher’s status.
* You can’t have more than 10 ms between the death of a philosopher and when it will print its death.
* Again, philosophers should avoid to die!