/*
 * bit_manipulation.h
 *
 * Created: 10/8/2022 4:34:20 PM
 *  Author: Seif
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(X,BIT_NUM) X|=(1<<BIT_NUM) // Setting bit to 1

#define CLEAR_BIT(X,BIT_NUM) X&=~(1<<BIT_NUM) // Setting the bit to 0

#define READ_BIT(X,BIT_NUM) ((X&(1<<BIT_NUM))>>BIT_NUM) // Reading bit 1 or 0

#define TOGGLE_BIT(X,BIT_NUM) X^=(1<<BIT_NUM) // Toggle bit, 1->0 or 0->1



#endif /* BIT_MANIPULATION_H_ */