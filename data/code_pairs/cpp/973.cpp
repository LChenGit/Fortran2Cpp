#ifndef LINE_SEARCH_SOLVER_H
#define LINE_SEARCH_SOLVER_H

#include <memory>

class line_search {
public:
    line_search() = default;
    virtual ~line_search() = default;
};

class line_search_solver {
private:
    std::unique_ptr<line_search> m_lineSearch;
    bool m_useLineSearch = false;

public:
    line_search_solver() = default;

    void get_line_search(std::unique_ptr<line_search>& ls) const {
        if (m_lineSearch) {
            ls = std::make_unique<line_search>(*m_lineSearch);
        }
    }

    void set_line_search(const line_search& ls) {
        m_lineSearch = std::make_unique<line_search>(ls);
    }

    void set_default() {
        line_search ls;
        set_line_search(ls);
    }

    bool is_line_search_defined() const {
        return bool(m_lineSearch);
    }

    bool get_use_search() const {
        return m_useLineSearch;
    }

    void set_use_search(bool x) {
        m_useLineSearch = x;
    }
};

#endif // LINE_SEARCH_SOLVER_H