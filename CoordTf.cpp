//*****************************************************************************************//
//**                                                                                     **//
//**                               CoordTf                                               **//
//**                                                                                     **//
//*****************************************************************************************//

#include "CoordTf.h"

CoordTf::MATRIX CoordTf::MATRIX::operator*(MATRIX mat) {
	CoordTf::MATRIX t = {};
	MatrixMultiply(&t, this, &mat);
	return t;
}

CoordTf::VECTOR4 CoordTf::VECTOR4::operator+(VECTOR4 v4) {
	CoordTf::VECTOR4 t = {};
	t.x = x + v4.x;
	t.y = y + v4.y;
	t.z = z + v4.z;
	t.w = w + v4.w;
	return t;
}

CoordTf::VECTOR4 CoordTf::VECTOR4::operator-(VECTOR4 v4) {
	CoordTf::VECTOR4 t = {};
	t.x = x - v4.x;
	t.y = y - v4.y;
	t.z = z - v4.z;
	t.w = w - v4.w;
	return t;
}

CoordTf::VECTOR4 CoordTf::VECTOR4::operator=(VECTOR4 v4) {
	x = v4.x;
	y = v4.y;
	z = v4.z;
	w = v4.w;
	return *this;
}

CoordTf::VECTOR3 CoordTf::VECTOR3::operator+(VECTOR3 v3) {
	CoordTf::VECTOR3 t = {};
	t.x = x + v3.x;
	t.y = y + v3.y;
	t.z = z + v3.z;
	return t;
}

CoordTf::VECTOR3 CoordTf::VECTOR3::operator-(VECTOR3 v3) {
	CoordTf::VECTOR3 t = {};
	t.x = x - v3.x;
	t.y = y - v3.y;
	t.z = z - v3.z;
	return t;
}

CoordTf::VECTOR3 CoordTf::VECTOR3::operator=(VECTOR3 v3) {
	x = v3.x;
	y = v3.y;
	z = v3.z;
	return *this;
}

CoordTf::VECTOR2 CoordTf::VECTOR2::operator+(VECTOR2 v2) {
	CoordTf::VECTOR2 t = {};
	t.x = x + v2.x;
	t.y = y + v2.y;
	return t;
}

CoordTf::VECTOR2 CoordTf::VECTOR2::operator-(VECTOR2 v2) {
	CoordTf::VECTOR2 t = {};
	t.x = x - v2.x;
	t.y = y - v2.y;
	return t;
}

CoordTf::VECTOR2 CoordTf::VECTOR2::operator=(VECTOR2 v2) {
	x = v2.x;
	y = v2.y;
	return *this;
}

void CoordTf::MatrixIdentity(MATRIX* mat) {
	mat->_11 = 1.0f; mat->_12 = 0.0f; mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = 1.0f; mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = 0.0f; mat->_33 = 1.0f; mat->_34 = 0.0f;
	mat->_41 = 0.0f; mat->_42 = 0.0f; mat->_43 = 0.0f; mat->_44 = 1.0f;
}

void CoordTf::MatrixScaling(MATRIX* mat, float sizex, float sizey, float sizez) {
	mat->_11 = sizex; mat->_12 = 0.0f; mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = sizey; mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = 0.0f; mat->_33 = sizez; mat->_34 = 0.0f;
	mat->_41 = 0.0f; mat->_42 = 0.0f; mat->_43 = 0.0f; mat->_44 = 1.0f;
}

void CoordTf::MatrixRotationX(MATRIX* mat, float theta) {
	float the = theta * 3.14f / 180.0f;
	mat->_11 = 1.0f; mat->_12 = 0.0f; mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = (float)cos(the); mat->_23 = (float)sin(the); mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = -(float)sin(the); mat->_33 = (float)cos(the); mat->_34 = 0.0f;
	mat->_41 = 0.0f; mat->_42 = 0.0f; mat->_43 = 0.0f; mat->_44 = 1.0f;
}

void CoordTf::MatrixRotationY(MATRIX* mat, float theta) {
	float the = theta * 3.14f / 180.0f;
	mat->_11 = (float)cos(the); mat->_12 = 0.0f; mat->_13 = -(float)sin(the); mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = 1.0f; mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = (float)sin(the); mat->_32 = 0.0f; mat->_33 = (float)cos(the); mat->_34 = 0.0f;
	mat->_41 = 0.0f; mat->_42 = 0.0f; mat->_43 = 0.0f; mat->_44 = 1.0f;
}

void CoordTf::MatrixRotationZ(MATRIX* mat, float theta) {
	float the = theta * 3.14f / 180.0f;
	mat->_11 = (float)cos(the); mat->_12 = (float)sin(the); mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = -(float)sin(the); mat->_22 = (float)cos(the); mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = 0.0f; mat->_33 = 1.0f; mat->_34 = 0.0f;
	mat->_41 = 0.0f; mat->_42 = 0.0f; mat->_43 = 0.0f; mat->_44 = 1.0f;
}

void CoordTf::MatrixTranslation(MATRIX* mat, float movx, float movy, float movz) {
	mat->_11 = 1.0f; mat->_12 = 0.0f; mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = 1.0f; mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = 0.0f; mat->_33 = 1.0f; mat->_34 = 0.0f;
	mat->_41 = movx; mat->_42 = movy; mat->_43 = movz; mat->_44 = 1.0f;
}

void CoordTf::MatrixAddition(MATRIX* mat, MATRIX* mat1, MATRIX* mat2) {
	mat->_11 = mat1->_11 + mat2->_11;
	mat->_12 = mat1->_12 + mat2->_12;
	mat->_13 = mat1->_13 + mat2->_13;
	mat->_14 = mat1->_14 + mat2->_14;

	mat->_21 = mat1->_21 + mat2->_21;
	mat->_22 = mat1->_22 + mat2->_22;
	mat->_23 = mat1->_23 + mat2->_23;
	mat->_24 = mat1->_24 + mat2->_24;

	mat->_31 = mat1->_31 + mat2->_31;
	mat->_32 = mat1->_32 + mat2->_32;
	mat->_33 = mat1->_33 + mat2->_33;
	mat->_34 = mat1->_34 + mat2->_34;

	mat->_41 = mat1->_41 + mat2->_41;
	mat->_42 = mat1->_42 + mat2->_42;
	mat->_43 = mat1->_43 + mat2->_43;
	mat->_44 = mat1->_44 + mat2->_44;
}

void CoordTf::MatrixMultiply(MATRIX* mat, MATRIX* mat1, MATRIX* mat2) {
	mat->_11 = mat1->_11 * mat2->_11 + mat1->_12 * mat2->_21 + mat1->_13 * mat2->_31 + mat1->_14 * mat2->_41;
	mat->_12 = mat1->_11 * mat2->_12 + mat1->_12 * mat2->_22 + mat1->_13 * mat2->_32 + mat1->_14 * mat2->_42;
	mat->_13 = mat1->_11 * mat2->_13 + mat1->_12 * mat2->_23 + mat1->_13 * mat2->_33 + mat1->_14 * mat2->_43;
	mat->_14 = mat1->_11 * mat2->_14 + mat1->_12 * mat2->_24 + mat1->_13 * mat2->_34 + mat1->_14 * mat2->_44;

	mat->_21 = mat1->_21 * mat2->_11 + mat1->_22 * mat2->_21 + mat1->_23 * mat2->_31 + mat1->_24 * mat2->_41;
	mat->_22 = mat1->_21 * mat2->_12 + mat1->_22 * mat2->_22 + mat1->_23 * mat2->_32 + mat1->_24 * mat2->_42;
	mat->_23 = mat1->_21 * mat2->_13 + mat1->_22 * mat2->_23 + mat1->_23 * mat2->_33 + mat1->_24 * mat2->_43;
	mat->_24 = mat1->_21 * mat2->_14 + mat1->_22 * mat2->_24 + mat1->_23 * mat2->_34 + mat1->_24 * mat2->_44;

	mat->_31 = mat1->_31 * mat2->_11 + mat1->_32 * mat2->_21 + mat1->_33 * mat2->_31 + mat1->_34 * mat2->_41;
	mat->_32 = mat1->_31 * mat2->_12 + mat1->_32 * mat2->_22 + mat1->_33 * mat2->_32 + mat1->_34 * mat2->_42;
	mat->_33 = mat1->_31 * mat2->_13 + mat1->_32 * mat2->_23 + mat1->_33 * mat2->_33 + mat1->_34 * mat2->_43;
	mat->_34 = mat1->_31 * mat2->_14 + mat1->_32 * mat2->_24 + mat1->_33 * mat2->_34 + mat1->_34 * mat2->_44;

	mat->_41 = mat1->_41 * mat2->_11 + mat1->_42 * mat2->_21 + mat1->_43 * mat2->_31 + mat1->_44 * mat2->_41;
	mat->_42 = mat1->_41 * mat2->_12 + mat1->_42 * mat2->_22 + mat1->_43 * mat2->_32 + mat1->_44 * mat2->_42;
	mat->_43 = mat1->_41 * mat2->_13 + mat1->_42 * mat2->_23 + mat1->_43 * mat2->_33 + mat1->_44 * mat2->_43;
	mat->_44 = mat1->_41 * mat2->_14 + mat1->_42 * mat2->_24 + mat1->_43 * mat2->_34 + mat1->_44 * mat2->_44;
}

static void swap(float* a, float* b) {
	float tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void CoordTf::MatrixTranspose(MATRIX* mat) {
	swap(&mat->_12, &mat->_21);
	swap(&mat->_13, &mat->_31);
	swap(&mat->_14, &mat->_41);
	swap(&mat->_23, &mat->_32);
	swap(&mat->_24, &mat->_42);
	swap(&mat->_34, &mat->_43);
}

void CoordTf::MatrixLookAtLH(MATRIX* mat, VECTOR3 pos, VECTOR3 dir, VECTOR3 up) {
	//z軸
	VECTOR3 in, z3;
	in.as(dir.x - pos.x, dir.y - pos.y, dir.z - pos.z);
	//正規化
	VectorNormalize(&z3, &in);

	//x軸(外積)
	VECTOR3 x3, xx3;
	VectorCross(&xx3, &up, &z3);
	VectorNormalize(&x3, &xx3);

	//y軸(外積)
	VECTOR3 y3;
	VectorCross(&y3, &z3, &x3);

	//平行移動(内積)
	VECTOR3 m3;
	m3.as(
		-(pos.x * x3.x + pos.y * x3.y + pos.z * x3.z),
		-(pos.x * y3.x + pos.y * y3.y + pos.z * y3.z),
		-(pos.x * z3.x + pos.y * z3.y + pos.z * z3.z)
	);

	mat->_11 = x3.x; mat->_12 = y3.x; mat->_13 = z3.x; mat->_14 = 0.0f;
	mat->_21 = x3.y; mat->_22 = y3.y; mat->_23 = z3.y; mat->_24 = 0.0f;
	mat->_31 = x3.z; mat->_32 = y3.z; mat->_33 = z3.z; mat->_34 = 0.0f;
	mat->_41 = m3.x; mat->_42 = m3.y; mat->_43 = m3.z; mat->_44 = 1.0f;
}

void CoordTf::MatrixPerspectiveFovLH(MATRIX* mat, float theta, float aspect, float Near, float Far) {
	float the = theta * 3.14f / 180.0f;
	//透視変換後y方向スケーリング
	float sy = 1.0f / ((float)tan(the / 2.0f));
	//x方向スケーリング
	float sx = sy / aspect;
	//z方向スケーリング
	float sz = Far / (Far - Near);

	mat->_11 = sx; mat->_12 = 0.0f; mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = sy; mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = 0.0f; mat->_33 = sz; mat->_34 = 1.0f;
	mat->_41 = 0.0f; mat->_42 = 0.0f; mat->_43 = -(sz * Near); mat->_44 = 0.0f;
}

void CoordTf::VectorMatrixMultiply(VECTOR3* v, MATRIX* mat) {
	float x = v->x;
	float y = v->y;
	float z = v->z;
	float w;

	v->x = x * mat->_11 + y * mat->_21 + z * mat->_31 + mat->_41;
	v->y = x * mat->_12 + y * mat->_22 + z * mat->_32 + mat->_42;
	v->z = x * mat->_13 + y * mat->_23 + z * mat->_33 + mat->_43;
	w = x * mat->_14 + y * mat->_24 + z * mat->_34 + mat->_44;
	v->x /= w;
	v->y /= w;
	v->z /= w;
}

void CoordTf::VectorAddition(VECTOR3* out, VECTOR3* in1, VECTOR3* in2) {
	out->x = in1->x + in2->x;
	out->y = in1->y + in2->y;
	out->z = in1->z + in2->z;
}

void CoordTf::VectorMultiply(VECTOR3* v, float f) {
	v->x *= f;
	v->y *= f;
	v->z *= f;
}

void CoordTf::VectorDivision(VECTOR3* v, float f) {
	v->x /= f;
	v->y /= f;
	v->z /= f;
}

//MatrixInverse内で使用
static double CalDetMat4x4(CoordTf::MATRIX* m) {

	return m->_11 * m->_22 * m->_33 * m->_44 + m->_11 * m->_23 * m->_34 * m->_42 + m->_11 * m->_24 * m->_32 * m->_43
		+ m->_12 * m->_21 * m->_34 * m->_43 + m->_12 * m->_23 * m->_31 * m->_44 + m->_12 * m->_24 * m->_33 * m->_41
		+ m->_13 * m->_21 * m->_32 * m->_44 + m->_13 * m->_22 * m->_34 * m->_41 + m->_13 * m->_24 * m->_31 * m->_42
		+ m->_14 * m->_21 * m->_33 * m->_42 + m->_14 * m->_22 * m->_31 * m->_43 + m->_14 * m->_23 * m->_32 * m->_41
		- m->_11 * m->_22 * m->_34 * m->_43 - m->_11 * m->_23 * m->_32 * m->_44 - m->_11 * m->_24 * m->_33 * m->_42
		- m->_12 * m->_21 * m->_33 * m->_44 - m->_12 * m->_23 * m->_34 * m->_41 - m->_12 * m->_24 * m->_31 * m->_43
		- m->_13 * m->_21 * m->_34 * m->_42 - m->_13 * m->_22 * m->_31 * m->_44 - m->_13 * m->_24 * m->_32 * m->_41
		- m->_14 * m->_21 * m->_32 * m->_43 - m->_14 * m->_22 * m->_33 * m->_41 - m->_14 * m->_23 * m->_31 * m->_42;
}

bool CoordTf::MatrixInverse(MATRIX* invm, MATRIX* m) {

	double det = CalDetMat4x4(m);
	if (fabs(det) < 0) {
		return false;
	}
	else {
		float inv_det = (float)(1.0 / det);

		invm->_11 = inv_det * (m->_22 * m->_33 * m->_44 + m->_23 * m->_34 * m->_42 + m->_24 * m->_32 * m->_43 - m->_22 * m->_34 * m->_43 - m->_23 * m->_32 * m->_44 - m->_24 * m->_33 * m->_42);
		invm->_12 = inv_det * (m->_12 * m->_34 * m->_43 + m->_13 * m->_32 * m->_44 + m->_14 * m->_33 * m->_42 - m->_12 * m->_33 * m->_44 - m->_13 * m->_34 * m->_42 - m->_14 * m->_32 * m->_43);
		invm->_13 = inv_det * (m->_12 * m->_23 * m->_44 + m->_13 * m->_24 * m->_42 + m->_14 * m->_22 * m->_43 - m->_12 * m->_24 * m->_43 - m->_13 * m->_22 * m->_44 - m->_14 * m->_23 * m->_42);
		invm->_14 = inv_det * (m->_12 * m->_24 * m->_33 + m->_13 * m->_22 * m->_34 + m->_14 * m->_23 * m->_32 - m->_12 * m->_23 * m->_34 - m->_13 * m->_24 * m->_32 - m->_14 * m->_22 * m->_33);

		invm->_21 = inv_det * (m->_21 * m->_34 * m->_43 + m->_23 * m->_31 * m->_44 + m->_24 * m->_33 * m->_41 - m->_21 * m->_33 * m->_44 - m->_23 * m->_34 * m->_41 - m->_24 * m->_31 * m->_43);
		invm->_22 = inv_det * (m->_11 * m->_33 * m->_44 + m->_13 * m->_34 * m->_41 + m->_14 * m->_31 * m->_43 - m->_11 * m->_34 * m->_43 - m->_13 * m->_31 * m->_44 - m->_14 * m->_33 * m->_41);
		invm->_23 = inv_det * (m->_11 * m->_24 * m->_43 + m->_13 * m->_21 * m->_44 + m->_14 * m->_23 * m->_41 - m->_11 * m->_23 * m->_44 - m->_13 * m->_24 * m->_41 - m->_14 * m->_21 * m->_43);
		invm->_24 = inv_det * (m->_11 * m->_23 * m->_34 + m->_13 * m->_24 * m->_31 + m->_14 * m->_21 * m->_33 - m->_11 * m->_24 * m->_33 - m->_13 * m->_21 * m->_34 - m->_14 * m->_23 * m->_31);

		invm->_31 = inv_det * (m->_21 * m->_32 * m->_44 + m->_22 * m->_34 * m->_41 + m->_24 * m->_31 * m->_42 - m->_21 * m->_34 * m->_42 - m->_22 * m->_31 * m->_44 - m->_24 * m->_32 * m->_41);
		invm->_32 = inv_det * (m->_11 * m->_34 * m->_42 + m->_12 * m->_31 * m->_44 + m->_14 * m->_32 * m->_41 - m->_11 * m->_32 * m->_44 - m->_12 * m->_34 * m->_41 - m->_14 * m->_31 * m->_42);
		invm->_33 = inv_det * (m->_11 * m->_22 * m->_44 + m->_12 * m->_24 * m->_41 + m->_14 * m->_21 * m->_42 - m->_11 * m->_24 * m->_42 - m->_12 * m->_21 * m->_44 - m->_14 * m->_22 * m->_41);
		invm->_34 = inv_det * (m->_11 * m->_24 * m->_32 + m->_12 * m->_21 * m->_34 + m->_14 * m->_22 * m->_31 - m->_11 * m->_22 * m->_34 - m->_12 * m->_24 * m->_31 - m->_14 * m->_21 * m->_32);

		invm->_41 = inv_det * (m->_21 * m->_33 * m->_42 + m->_22 * m->_31 * m->_43 + m->_23 * m->_32 * m->_41 - m->_21 * m->_32 * m->_43 - m->_22 * m->_33 * m->_41 - m->_23 * m->_31 * m->_42);
		invm->_42 = inv_det * (m->_11 * m->_32 * m->_43 + m->_12 * m->_33 * m->_41 + m->_13 * m->_31 * m->_42 - m->_11 * m->_33 * m->_42 - m->_12 * m->_31 * m->_43 - m->_13 * m->_32 * m->_41);
		invm->_43 = inv_det * (m->_11 * m->_23 * m->_42 + m->_12 * m->_21 * m->_43 + m->_13 * m->_22 * m->_41 - m->_11 * m->_22 * m->_43 - m->_12 * m->_23 * m->_41 - m->_13 * m->_21 * m->_42);
		invm->_44 = inv_det * (m->_11 * m->_22 * m->_33 + m->_12 * m->_23 * m->_31 + m->_13 * m->_21 * m->_32 - m->_11 * m->_23 * m->_32 - m->_12 * m->_21 * m->_33 - m->_13 * m->_22 * m->_31);

		return true;
	}
}

void CoordTf::MatrixViewPort(MATRIX* mat, int width, int height) {
	mat->_11 = width / 2.0f; mat->_12 = 0.0f; mat->_13 = 0.0f; mat->_14 = 0.0f;
	mat->_21 = 0.0f; mat->_22 = -height / 2.0f; mat->_23 = 0.0f; mat->_24 = 0.0f;
	mat->_31 = 0.0f; mat->_32 = 0.0f; mat->_33 = 1.0f; mat->_34 = 0.0f;
	mat->_41 = width / 2.0f; mat->_42 = height / 2.0f; mat->_43 = 0.0f; mat->_44 = 1.0f;
}

void CoordTf::Normalize(float* x, float* y, float* z, float* w) {
	float nor = (float)sqrt(*x * *x + *y * *y + *z * *z + *w * *w);
	if (nor != 0.0f) {
		*x = *x / nor;
		*y = *y / nor;
		*z = *z / nor;
		*w = *w / nor;
	}
	else {
		*x = 0.0f;
		*y = 0.0f;
		*z = 0.0f;
		*w = 0.0f;
	}
}

void CoordTf::VectorNormalize(VECTOR3* out, VECTOR3* in) {
	float nor = (float)sqrt(in->x * in->x + in->y * in->y + in->z * in->z);
	if (nor != 0.0f) {
		out->x = in->x / nor;
		out->y = in->y / nor;
		out->z = in->z / nor;
	}
	else {
		out->x = 0.0f;
		out->y = 0.0f;
		out->z = 0.0f;
	}
}

void CoordTf::VectorCross(VECTOR3* out, VECTOR3* in1, VECTOR3* in2) {
	out->x = in1->y * in2->z - in1->z * in2->y;
	out->y = in1->z * in2->x - in1->x * in2->z;
	out->z = in1->x * in2->y - in1->y * in2->x;
}

float CoordTf::VectorDot(VECTOR3* in1, VECTOR3* in2) {
	return in1->x * in2->x + in1->y * in2->y + in1->z * in2->z;
}

void CoordTf::StraightLinear(MATRIX* out, MATRIX* start, MATRIX* end, float t) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			out->m[y][x] = start->m[y][x] * (1.0f - t) + end->m[y][x] * t;
		}
	}
}

CoordTf::VECTOR3 CoordTf::CalcTangent(VECTOR3 pos0, VECTOR3 pos1, VECTOR3 pos2,
	VECTOR2 uv0, VECTOR2 uv1, VECTOR2 uv2, VECTOR3 normal) {

	VECTOR3 deltaPos1 = pos1 - pos0;
	VECTOR3 deltaPos2 = pos2 - pos0;

	VECTOR2 deltaUV1 = uv1 - uv0;
	VECTOR2 deltaUV2 = uv2 - uv0;

	float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);

	VectorMultiply(&deltaPos1, deltaUV2.y);
	VectorMultiply(&deltaPos2, deltaUV1.y);
	VECTOR3 tangent = deltaPos1 - deltaPos2;

	VectorMultiply(&deltaPos2, deltaUV1.x);
	VectorMultiply(&deltaPos1, deltaUV2.x);
	VECTOR3 bitangent = deltaPos2 - deltaPos1;

	VECTOR3 out = {};
	VectorCross(&out, &normal, &tangent);

	if (VectorDot(&out, &bitangent) < 0.0f) {
		tangent.x *= -1.0f;
		tangent.y *= -1.0f;
		tangent.z *= -1.0f;
	}

	return tangent;
}