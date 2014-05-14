// Code generated by Stan version 2.2

#include <stan/model/model_header.hpp>
#include <stan/common/command.hpp>

namespace blocker_model_namespace {

using std::vector;
using std::string;
using std::stringstream;
using stan::model::prob_grad;
using stan::math::get_base1;
using stan::math::initialize;
using stan::math::stan_print;
using stan::math::lgamma;
using stan::io::dump;
using std::istream;
using namespace stan::math;
using namespace stan::prob;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

class blocker_model : public prob_grad {
private:
    int N;
    vector<int> nt;
    vector<int> rt;
    vector<int> nc;
    vector<int> rc;
public:
    blocker_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad::prob_grad(0) {
        static const char* function__ = "blocker_model_namespace::blocker_model(%1%)";
        (void) function__; // dummy call to supress warning
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        context__.validate_dims("data initialization", "N", "int", context__.to_vec());
        N = int(0);
        vals_i__ = context__.vals_i("N");
        pos__ = 0;
        N = vals_i__[pos__++];
        context__.validate_dims("data initialization", "nt", "int", context__.to_vec(N));
        stan::math::validate_non_negative_index("nt", "N", N);
        nt = std::vector<int>(N,int(0));
        vals_i__ = context__.vals_i("nt");
        pos__ = 0;
        size_t nt_limit_0__ = N;
        for (size_t i_0__ = 0; i_0__ < nt_limit_0__; ++i_0__) {
            nt[i_0__] = vals_i__[pos__++];
        }
        context__.validate_dims("data initialization", "rt", "int", context__.to_vec(N));
        stan::math::validate_non_negative_index("rt", "N", N);
        rt = std::vector<int>(N,int(0));
        vals_i__ = context__.vals_i("rt");
        pos__ = 0;
        size_t rt_limit_0__ = N;
        for (size_t i_0__ = 0; i_0__ < rt_limit_0__; ++i_0__) {
            rt[i_0__] = vals_i__[pos__++];
        }
        context__.validate_dims("data initialization", "nc", "int", context__.to_vec(N));
        stan::math::validate_non_negative_index("nc", "N", N);
        nc = std::vector<int>(N,int(0));
        vals_i__ = context__.vals_i("nc");
        pos__ = 0;
        size_t nc_limit_0__ = N;
        for (size_t i_0__ = 0; i_0__ < nc_limit_0__; ++i_0__) {
            nc[i_0__] = vals_i__[pos__++];
        }
        context__.validate_dims("data initialization", "rc", "int", context__.to_vec(N));
        stan::math::validate_non_negative_index("rc", "N", N);
        rc = std::vector<int>(N,int(0));
        vals_i__ = context__.vals_i("rc");
        pos__ = 0;
        size_t rc_limit_0__ = N;
        for (size_t i_0__ = 0; i_0__ < rc_limit_0__; ++i_0__) {
            rc[i_0__] = vals_i__[pos__++];
        }

        // validate data
        try { 
            check_greater_or_equal(function__,N,0,"N");
        } catch (const std::exception& e) { 
            throw std::domain_error(std::string("Invalid value of N: ") + std::string(e.what()));
        };
        for (int k0__ = 0; k0__ < N; ++k0__) {
            try { 
                check_greater_or_equal(function__,nt[k0__],0,"nt[k0__]");
            } catch (const std::exception& e) { 
                throw std::domain_error(std::string("Invalid value of nt: ") + std::string(e.what()));
            };
        }
        for (int k0__ = 0; k0__ < N; ++k0__) {
            try { 
                check_greater_or_equal(function__,rt[k0__],0,"rt[k0__]");
            } catch (const std::exception& e) { 
                throw std::domain_error(std::string("Invalid value of rt: ") + std::string(e.what()));
            };
        }
        for (int k0__ = 0; k0__ < N; ++k0__) {
            try { 
                check_greater_or_equal(function__,nc[k0__],0,"nc[k0__]");
            } catch (const std::exception& e) { 
                throw std::domain_error(std::string("Invalid value of nc: ") + std::string(e.what()));
            };
        }
        for (int k0__ = 0; k0__ < N; ++k0__) {
            try { 
                check_greater_or_equal(function__,rc[k0__],0,"rc[k0__]");
            } catch (const std::exception& e) { 
                throw std::domain_error(std::string("Invalid value of rc: ") + std::string(e.what()));
            };
        }


        // validate transformed data

        // set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        ++num_params_r__;
        ++num_params_r__;
        num_params_r__ += N;
        num_params_r__ += N;
        ++num_params_r__;
    }

    ~blocker_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;


        if (!(context__.contains_r("d")))
            throw std::runtime_error("variable d missing");
        vals_r__ = context__.vals_r("d");
        pos__ = 0U;
        context__.validate_dims("initialization", "d", "double", context__.to_vec());
        double d(0);
        d = vals_r__[pos__++];
        try { writer__.scalar_unconstrain(d); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable d: ") + e.what()); }

        if (!(context__.contains_r("sigmasq_delta")))
            throw std::runtime_error("variable sigmasq_delta missing");
        vals_r__ = context__.vals_r("sigmasq_delta");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigmasq_delta", "double", context__.to_vec());
        double sigmasq_delta(0);
        sigmasq_delta = vals_r__[pos__++];
        try { writer__.scalar_lb_unconstrain(0,sigmasq_delta); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable sigmasq_delta: ") + e.what()); }

        if (!(context__.contains_r("mu")))
            throw std::runtime_error("variable mu missing");
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu", "vector_d", context__.to_vec(N));
        vector_d mu(N);
        for (int j1__ = 0U; j1__ < N; ++j1__)
            mu(j1__) = vals_r__[pos__++];
        try { writer__.vector_unconstrain(mu); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable mu: ") + e.what()); }

        if (!(context__.contains_r("delta")))
            throw std::runtime_error("variable delta missing");
        vals_r__ = context__.vals_r("delta");
        pos__ = 0U;
        context__.validate_dims("initialization", "delta", "vector_d", context__.to_vec(N));
        vector_d delta(N);
        for (int j1__ = 0U; j1__ < N; ++j1__)
            delta(j1__) = vals_r__[pos__++];
        try { writer__.vector_unconstrain(delta); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable delta: ") + e.what()); }

        if (!(context__.contains_r("delta_new")))
            throw std::runtime_error("variable delta_new missing");
        vals_r__ = context__.vals_r("delta_new");
        pos__ = 0U;
        context__.validate_dims("initialization", "delta_new", "double", context__.to_vec());
        double delta_new(0);
        delta_new = vals_r__[pos__++];
        try { writer__.scalar_unconstrain(delta_new); } catch (const std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable delta_new: ") + e.what()); }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        T__ d;
        (void) d;   // dummy to suppress unused var warning
        if (jacobian__)
            d = in__.scalar_constrain(lp__);
        else
            d = in__.scalar_constrain();

        T__ sigmasq_delta;
        (void) sigmasq_delta;   // dummy to suppress unused var warning
        if (jacobian__)
            sigmasq_delta = in__.scalar_lb_constrain(0,lp__);
        else
            sigmasq_delta = in__.scalar_lb_constrain(0);

        Eigen::Matrix<T__,Eigen::Dynamic,1>  mu;
        (void) mu;   // dummy to suppress unused var warning
        if (jacobian__)
            mu = in__.vector_constrain(N,lp__);
        else
            mu = in__.vector_constrain(N);

        Eigen::Matrix<T__,Eigen::Dynamic,1>  delta;
        (void) delta;   // dummy to suppress unused var warning
        if (jacobian__)
            delta = in__.vector_constrain(N,lp__);
        else
            delta = in__.vector_constrain(N);

        T__ delta_new;
        (void) delta_new;   // dummy to suppress unused var warning
        if (jacobian__)
            delta_new = in__.scalar_constrain(lp__);
        else
            delta_new = in__.scalar_constrain();


        // transformed parameters
        T__ sigma_delta;
        (void) sigma_delta;   // dummy to suppress unused var warning

        // initialized transformed params to avoid seg fault on val access
                stan::math::fill(sigma_delta,DUMMY_VAR__);

        stan::math::assign(sigma_delta, sqrt(sigmasq_delta));

        // validate transformed parameters
        if (stan::math::is_uninitialized(sigma_delta)) {
            std::stringstream msg__;
            msg__ << "Undefined transformed parameter: sigma_delta";
            throw std::runtime_error(msg__.str());
        }

        const char* function__ = "validate transformed params %1%";
        (void) function__; // dummy to suppress unused var warning
        try { 
            check_greater_or_equal(function__,sigma_delta,0,"sigma_delta");
        } catch (const std::exception& e) { 
            throw std::domain_error(std::string("Invalid value of sigma_delta: ") + std::string(e.what()));
        };
        // model body
        lp_accum__.add(binomial_logit_log<propto__>(rt, nt, add(mu,delta)));
        lp_accum__.add(binomial_logit_log<propto__>(rc, nc, mu));
        lp_accum__.add(student_t_log<propto__>(delta, 4, d, sigma_delta));
        lp_accum__.add(normal_log<propto__>(mu, 0, sqrt(100000.0)));
        lp_accum__.add(normal_log<propto__>(d, 0, 1000.0));
        lp_accum__.add(inv_gamma_log<propto__>(sigmasq_delta, 0.001, 0.001));
        lp_accum__.add(student_t_log<propto__>(delta_new, 4, d, sigma_delta));

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("d");
        names__.push_back("sigmasq_delta");
        names__.push_back("mu");
        names__.push_back("delta");
        names__.push_back("delta_new");
        names__.push_back("sigma_delta");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "blocker_model_namespace::write_array(%1%)";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        double d = in__.scalar_constrain();
        double sigmasq_delta = in__.scalar_lb_constrain(0);
        vector_d mu = in__.vector_constrain(N);
        vector_d delta = in__.vector_constrain(N);
        double delta_new = in__.scalar_constrain();
        vars__.push_back(d);
        vars__.push_back(sigmasq_delta);
        for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(mu[k_0__]);
        }
        for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(delta[k_0__]);
        }
        vars__.push_back(delta_new);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        double sigma_delta(0.0);
        (void) sigma_delta;   // dummy to suppress unused var warning

        stan::math::assign(sigma_delta, sqrt(sigmasq_delta));

        // validate transformed parameters
        try { 
            check_greater_or_equal(function__,sigma_delta,0,"sigma_delta");
        } catch (const std::exception& e) { 
            throw std::domain_error(std::string("Invalid value of sigma_delta: ") + std::string(e.what()));
        };

        // write transformed parameters
        vars__.push_back(sigma_delta);

        if (!include_gqs__) return;
        // declare and define generated quantities


        // validate generated quantities

        // write generated quantities
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }


    void write_csv_header(std::ostream& o__) const {
        stan::io::csv_writer writer__(o__);
        writer__.comma();
        o__ << "d";
        writer__.comma();
        o__ << "sigmasq_delta";
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            writer__.comma();
            o__ << "mu" << '.' << k_0__;
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            writer__.comma();
            o__ << "delta" << '.' << k_0__;
        }
        writer__.comma();
        o__ << "delta_new";
        writer__.comma();
        o__ << "sigma_delta";
        writer__.newline();
    }

    template <typename RNG>
    void write_csv(RNG& base_rng__,
                   std::vector<double>& params_r__,
                   std::vector<int>& params_i__,
                   std::ostream& o__,
                   std::ostream* pstream__ = 0) const {
        stan::io::reader<double> in__(params_r__,params_i__);
        stan::io::csv_writer writer__(o__);
        static const char* function__ = "blocker_model_namespace::write_csv(%1%)";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        double d = in__.scalar_constrain();
        writer__.write(d);
        double sigmasq_delta = in__.scalar_lb_constrain(0);
        writer__.write(sigmasq_delta);
        vector_d mu = in__.vector_constrain(N);
        writer__.write(mu);
        vector_d delta = in__.vector_constrain(N);
        writer__.write(delta);
        double delta_new = in__.scalar_constrain();
        writer__.write(delta_new);

        // declare, define and validate transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        double sigma_delta(0.0);
        (void) sigma_delta;   // dummy to suppress unused var warning

        stan::math::assign(sigma_delta, sqrt(sigmasq_delta));

        try { 
            check_greater_or_equal(function__,sigma_delta,0,"sigma_delta");
        } catch (const std::exception& e) { 
            throw std::domain_error(std::string("Invalid value of sigma_delta: ") + std::string(e.what()));
        };

        // write transformed parameters
        writer__.write(sigma_delta);

        // declare and define generated quantities


        // validate generated quantities

        // write generated quantities
        writer__.newline();
    }

    template <typename RNG>
    void write_csv(RNG& base_rng,
                   Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                   std::ostream& o,
                   std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<int> params_i_vec;  // dummy
      write_csv(base_rng, params_r_vec, params_i_vec, o, pstream);
    }

    static std::string model_name() {
        return "blocker_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "d";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigmasq_delta";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "delta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "delta_new";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_delta";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "d";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigmasq_delta";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "delta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "delta_new";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_delta";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__) return;
    }

}; // model

} // namespace

typedef blocker_model_namespace::blocker_model stan_model;
