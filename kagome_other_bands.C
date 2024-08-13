#include <string>
#include <iomanip>

void kagome_other_bands()
{
    gStyle->SetTitleFontSize(0.025);
    
    // INSERIRE LIVELLI DI FERMI
    Double_t fermi_r{5.6474};
    Double_t fermi_w{5.5563};

    Double_t sn1_fermi_r{3.9751};
    Double_t sn1_fermi_w{3.9995};

    Double_t ymax{0.5};
    Double_t ymin{-0.5};

    Int_t n_points{128};

    TGraph *g = new TGraph("kagome_bands_new.dat");

    for (Int_t i{}; i < g->GetN(); i++)
    {
        Double_t y = g->GetPointY(i) + fermi_w - fermi_r;
        g->SetPointY(i, y);
    }

    Double_t G = g->GetPointX(0);
    Double_t M = g->GetPointX(n_points);
    Double_t K = g->GetPointX(2 * n_points);
    Double_t G2 = g->GetPointX(3 * n_points);
    Double_t A = g->GetPointX(4 * n_points);
    Double_t L = g->GetPointX(5 * n_points);
    Double_t H = g->GetPointX(6 * n_points);
    Double_t A2 = g->GetPointX(7 * n_points);

    g->SetLineColor(4);
    g->SetLineWidth(1);
    g->GetYaxis()->SetRangeUser(-2, 2);
    g->GetXaxis()->SetRangeUser(0, A2);
    g->GetYaxis()->SetTitle("#font[132]{Energy (eV)}");
    g->SetTitle("#font[132]{CsV_{3}Sb_{5}}");
    g->GetYaxis()->SetLabelFont(132);
    g->GetXaxis()->SetDecimals(kTRUE);
    g->GetYaxis()->SetDecimals(kTRUE);

    TGraph *sn1 = new TGraph("kagome_4_Sn.dat");

    /*l1->SetLineColor(14);
    l2->SetLineColor(14);
    l3->SetLineColor(14);
    l4->SetLineColor(14);
    l5->SetLineColor(14);
    l6->SetLineColor(14);
    l7->SetLineColor(14);
    l8->SetLineColor(14);*/

    TLine *l = new TLine(0, 0, A2, 0);
    l->SetLineColor(kRed);
    l->SetLineStyle(2);

    for (Int_t i{}; i < sn1->GetN(); i++)
    {
        Double_t y = sn1->GetPointY(i) + sn1_fermi_w - sn1_fermi_r;
        sn1->SetPointY(i, y);
    }

    sn1->SetLineColor(4);
    sn1->SetLineWidth(1);
    sn1->GetYaxis()->SetRangeUser(-1, 1);
    sn1->GetXaxis()->SetRangeUser(0, A2);
    sn1->GetYaxis()->SetTitle("Energy (eV)");
    sn1->SetTitle("Drogaggio all'1% di Sn");

    

    Double_t G_sn_1 = sn1->GetPointX(0);
    Double_t M_sn_1 = sn1->GetPointX(n_points);
    Double_t K_sn_1 = sn1->GetPointX(2 * n_points);
    Double_t G2_sn_1 = sn1->GetPointX(3 * n_points);
    Double_t A_sn_1 = sn1->GetPointX(4 * n_points);
    Double_t L_sn_1 = sn1->GetPointX(5 * n_points);
    Double_t H_sn_1 = sn1->GetPointX(6 * n_points);
    Double_t A2_sn_1 = sn1->GetPointX(7 * n_points);

    TGraph *rndm = new TGraph();
    rndm->SetLineColor(0);
    rndm->SetMarkerSize(0);
    rndm->SetMarkerStyle(0);
    rndm->SetMarkerColor(0);


    TLine *l1_g = new TLine(G, -2, G, 2);
    TLine *l2_g = new TLine(M, -2, M, 2);
    TLine *l3_g = new TLine(K, -2, K, 2);
    TLine *l4_g = new TLine(G2, -2, G2, 2);
    TLine *l5_g = new TLine(A, -2, A, 2);
    TLine *l6_g = new TLine(L, -2, L, 2);
    TLine *l7_g = new TLine(H, -2, H, 2);
    TLine *l8_g = new TLine(A2, -2, A2, 2);

    TLine *l1 = new TLine(G, ymin, G, ymax);
    TLine *l2 = new TLine(M, ymin, M, ymax);
    TLine *l3 = new TLine(K, ymin, K, ymax);
    TLine *l4 = new TLine(G2, ymin, G2, ymax);
    TLine *l5 = new TLine(A, ymin, A, ymax);
    TLine *l6 = new TLine(L, ymin, L, ymax);
    TLine *l7 = new TLine(H, ymin, H, ymax);
    TLine *l8 = new TLine(A2, ymin, A2, ymax);

    TLegend *Gamma = new TLegend(0.095, 0.05, 0.12, 0.098);
    Gamma->AddEntry(rndm, "#Gamma");
    Gamma->SetBorderSize(0);

    TLegend *m = new TLegend(0.198, 0.05, 0.323, 0.098);
    m->AddEntry(rndm, "#font[132]{M}");
    m->SetBorderSize(0);

    TLegend *k = new TLegend(0.278, 0.05, 0.403, 0.098);
    k->AddEntry(rndm, "#font[132]{K}");
    k->SetBorderSize(0);

    TLegend *Gamma2 = new TLegend(0.437, 0.05, 0.562, 0.098);
    Gamma2->AddEntry(rndm, "#Gamma");
    Gamma2->SetBorderSize(0);

    TLegend *a = new TLegend(0.5, 0.05, 0.625, 0.098);
    a->AddEntry(rndm, "#font[132]{A}");
    a->SetBorderSize(0);

    TLegend *lp = new TLegend(0.637, 0.05, 0.762, 0.098);
    lp->AddEntry(rndm, "#font[132]{L}");
    lp->SetBorderSize(0);

    TLegend *h = new TLegend(0.7125, 0.05, 0.8375, 0.098);
    h->AddEntry(rndm, "#font[132]{H}");
    h->SetBorderSize(0);

    TLegend *a2 = new TLegend(0.865, 0.05, 0.99, 0.098);
    a2->AddEntry(rndm, "#font[132]{A}");
    a2->SetBorderSize(0);

    TCanvas *c_Sn = new TCanvas();
    sn1->Draw("AL");
    l->Draw();
    l1_g->Draw();
    l2_g->Draw();
    l3_g->Draw();
    l4_g->Draw();
    l5_g->Draw();
    l6_g->Draw();
    l7_g->Draw();
    l8_g->Draw();
    Gamma->Draw("SAME");
    m->Draw("SAME");
    k->Draw("SAME");
    Gamma2->Draw("SAME");
    a->Draw("SAME");
    lp->Draw("SAME");
    h->Draw("SAME");
    a2->Draw("SAME");

    TCanvas *c = new TCanvas();

    g->Draw("AL");
    // h->Draw("SAME");
    l->Draw();
    l1_g->Draw();
    l2_g->Draw();
    l3_g->Draw();
    l4_g->Draw();
    l5_g->Draw();
    l6_g->Draw();
    l7_g->Draw();
    l8_g->Draw();
    Gamma->Draw("SAME");
    m->Draw("SAME");
    k->Draw("SAME");
    Gamma2->Draw("SAME");
    a->Draw("SAME");
    lp->Draw("SAME");
    h->Draw("SAME");
    a2->Draw("SAME");
}