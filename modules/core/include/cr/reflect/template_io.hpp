#pragma once

#pragma region n_fields

/// 定义结构体模板IO函数（含1字段）
#define cr_template_io_1f(S, f1) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
	}

/// 定义结构体模板IO函数（含2字段）
#define cr_template_io_2f(S, f1, f2) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
	}

/// 定义结构体模板IO函数（含3字段）
#define cr_template_io_3f(S, f1, f2, f3) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
	}

/// 定义结构体模板IO函数（含4字段）
#define cr_template_io_4f(S, f1, f2, f3, f4) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
	}

/// 定义结构体模板IO函数（含5字段）
#define cr_template_io_5f(S, f1, f2, f3, f4, f5) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
	}

/// 定义结构体模板IO函数（含6字段）
#define cr_template_io_6f(S, f1, f2, f3, f4, f5, f6) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5) \
			&& archive.get_field(#f6, t.f6); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
		archive.set_field(#f6, t.f6); \
	}

/// 定义结构体模板IO函数（含7字段）
#define cr_template_io_7f(S, f1, f2, f3, f4, f5, f6, f7) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5) \
			&& archive.get_field(#f6, t.f6) \
			&& archive.get_field(#f7, t.f7); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
		archive.set_field(#f6, t.f6); \
		archive.set_field(#f7, t.f7); \
	}

/// 定义结构体模板IO函数（含8字段）
#define cr_template_io_8f(S, f1, f2, f3, f4, f5, f6, f7, f8) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5) \
			&& archive.get_field(#f6, t.f6) \
			&& archive.get_field(#f7, t.f7) \
			&& archive.get_field(#f8, t.f8); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
		archive.set_field(#f6, t.f6); \
		archive.set_field(#f7, t.f7); \
		archive.set_field(#f8, t.f8); \
	}

/// 定义结构体模板IO函数（含9字段）
#define cr_template_io_9f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5) \
			&& archive.get_field(#f6, t.f6) \
			&& archive.get_field(#f7, t.f7) \
			&& archive.get_field(#f8, t.f8) \
			&& archive.get_field(#f9, t.f9); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
		archive.set_field(#f6, t.f6); \
		archive.set_field(#f7, t.f7); \
		archive.set_field(#f8, t.f8); \
		archive.set_field(#f9, t.f9); \
	}

/// 定义结构体模板IO函数（含10字段）
#define cr_template_io_10f(S, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5) \
			&& archive.get_field(#f6, t.f6) \
			&& archive.get_field(#f7, t.f7) \
			&& archive.get_field(#f8, t.f8) \
			&& archive.get_field(#f9, t.f9) \
			&& archive.get_field(#f10, t.f10); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
		archive.set_field(#f6, t.f6); \
		archive.set_field(#f7, t.f7); \
		archive.set_field(#f8, t.f8); \
		archive.set_field(#f9, t.f9); \
		archive.set_field(#f10, t.f10); \
	}


#pragma endregion
#pragma region n_fields_with_base


/// 定义结构体模板IO函数（含基类和1字段）
#define cr_template_io_b1f(S, B, f1) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return load((B&)t, archive) \
			&& archive.get_field(#f1, t.f1); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		save((const B&)t, archive); \
		archive.set_field(#f1, t.f1); \
	}

/// 定义结构体模板IO函数（含基类和2字段）
#define cr_template_io_b2f(S, B, f1, f2) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return load((B&)t, archive) \
			&& archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		save((const B&)t, archive) \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
	}

/// 定义结构体模板IO函数（含基类和3字段）
#define cr_template_io_b3f(S, B, f1, f2, f3) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return load((B&)t, archive) \
			&& archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		save((const B&)t, archive); \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
	}

/// 定义结构体模板IO函数（含基类和4字段）
#define cr_template_io_b4f(S, B, f1, f2, f3, f4) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return load((B&)t, archive) \
			&& archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		save((const B&)t, archive); \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
	}

/// 定义结构体模板IO函数（含基类和5字段）
#define cr_template_io_b5f(S, B, f1, f2, f3, f4, f5) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return load((B&)t, archive) \
			&& archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		save((const B&)t, archive); \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
	}

/// 定义结构体模板IO函数（含基类和6字段）
#define cr_template_io_b6f(S, B, f1, f2, f3, f4, f5, f6) \
	template<typename T, typename A> \
	bool load(S<T>& t, A& archive) { \
		return load((B&)t, archive) \
			&& archive.get_field(#f1, t.f1) \
			&& archive.get_field(#f2, t.f2) \
			&& archive.get_field(#f3, t.f3) \
			&& archive.get_field(#f4, t.f4) \
			&& archive.get_field(#f5, t.f5) \
			&& archive.get_field(#f6, t.f6); \
	} \
	template<typename T, typename A> \
	void save(const S<T>& t, A& archive) { \
		save((const B&)t, archive); \
		archive.set_field(#f1, t.f1); \
		archive.set_field(#f2, t.f2); \
		archive.set_field(#f3, t.f3); \
		archive.set_field(#f4, t.f4); \
		archive.set_field(#f5, t.f5); \
		archive.set_field(#f6, t.f6); \
	}
#pragma endregion


