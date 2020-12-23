#ifndef TCHAIN_ASSERT_H_
#define TCHAIN_ASSERT_H_

#define TCHAIN_CONCATENATE( X, Y ) TCHAIN_CONCATENATE1( X, Y )
#define TCHAIN_CONCATENATE1( X, Y ) TCHAIN_CONCATENATE2(X,Y)
#define TCHAIN_CONCATENATE2( X, Y ) X##Y
#define TCHAIN_ASSERT(e) /*lint -save */ extern char TCHAIN_CONCATENATE (assertion, __LINE__) [(e)?1:-1] /*lint -restore*/

#endif /*  TCHAIN_ASSERT_H_ */
