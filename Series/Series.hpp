/**
 * @file Series.hpp
 * @brief Series (type of content/video) class header definition.
 * @author Ximena Patricia García Magdaleno - A01642371
 * @date 2026-06-03
 */

#pragma once

// ── Includes de la STL ─────────────────────────────────────────────────────
#include <string>
#include <vector>

// ── Includes del proyecto ──────────────────────────────────────────────────
//#include "OtraDependencia.hpp"

/**
 * @class Series
 * @brief This class inherits from Video class and works to create an object of typr Series, which almacens 
 * objects of type Episode, as well as the season from which it belongs.
 *
 * Aquí puedes agregar notas de uso, invariantes importantes,
 * o ejemplos rápidos si aplica.
 */
class Series {
public:
    // ── Constructores / Destructor ─────────────────────────────────────────
    Series();
    ~Series();

    // ── Getters / Setters ──────────────────────────────────────────────────
    int  getValor() const;
    void setValor(int valor);

    // ── Métodos públicos ───────────────────────────────────────────────────
    void inicializar();
    bool ejecutar();

private:
    // ── Atributos ──────────────────────────────────────────────────────────
    int    valor_;
    bool   activo_;

    // ── Métodos privados ───────────────────────────────────────────────────
    void helper_();

protected: 

};